#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""progress.py - progress lines for the long searches, off unless PROGRESS=1.

`make` exports PROGRESS=1 (`make rules PROGRESS=0` turns it off again), so a person who starts a search through make sees where it is;
a tool run directly, by an agent or a script, prints exactly what it printed before. The lines go to stderr, so the totals a tool prints
on stdout stay as they were:

    [permute-stores] 12/70 17%  elapsed 41m02s  eta 3h20m  running 1FC270, 1B9CA0  last 1E64C8: 6 -> 5

A line comes when an item finishes (at most one every few seconds) and, from a heartbeat thread, every 15 seconds while nothing finishes:
one slow item does not leave the screen blank. Workers call `begin` and `tick` themselves, in whatever order they finish:

    progress = Progress(len(items), 'rules')
    def work(item):
        progress.begin(item.name)
        ...
        progress.tick('6 -> 5', item.name)       # thread-safe
    progress.done()                               # stops the heartbeat
"""
import os
import sys
import threading
import time


def enabled():
    return os.environ.get('PROGRESS') == '1'


def clock(seconds):
    seconds = int(seconds)
    if seconds >= 3600:
        return f'{seconds // 3600}h{seconds % 3600 // 60:02d}m'
    if seconds >= 60:
        return f'{seconds // 60}m{seconds % 60:02d}s'
    return f'{seconds}s'


class Progress:
    def __init__(self, total, label, interval=5.0, heartbeat=15.0, stream=None):
        self.total, self.label, self.interval = total, label, interval
        self.stream = stream or sys.stderr
        self.count, self.start, self.last = 0, time.monotonic(), 0.0
        self.running, self.note = [], ''
        self.active = enabled()
        self.lock = threading.Lock()
        self.stopped = threading.Event()
        if self.active and heartbeat:
            threading.Thread(target=self.beat, args=(heartbeat,), daemon=True).start()

    def eta(self):
        """The time left, estimated from the average of what is done ('' before the first item)."""
        if not self.count:
            return ''
        elapsed = time.monotonic() - self.start
        return clock(elapsed / self.count * (self.total - self.count))

    def line(self):
        percent = 100 * self.count // self.total if self.total else 100
        text = f'[{self.label}] {self.count}/{self.total} {percent}%  elapsed {clock(time.monotonic() - self.start)}'
        if self.count < self.total and self.eta():
            text += f'  eta {self.eta()}'
        if self.running:
            shown = ', '.join(self.running[:3]) + (f' +{len(self.running) - 3}' if len(self.running) > 3 else '')
            text += f'  running {shown}'
        if self.note:
            text += f'  last {self.note}'
        return text

    def emit(self):
        self.last = time.monotonic()
        print(self.line(), file=self.stream, flush=True)

    def begin(self, name):
        """An item started (the heartbeat names what is running)."""
        if self.active:
            with self.lock:
                self.running.append(str(name))

    def tick(self, note='', name=None, step=1):
        """An item is done: a line when the interval has passed since the last, and for the last item. Thread-safe."""
        with self.lock:
            self.count += step
            if note:
                self.note = note
            if name is not None and str(name) in self.running:
                self.running.remove(str(name))
            if self.active and (time.monotonic() - self.last >= self.interval or self.count >= self.total):
                self.emit()

    def beat(self, seconds):
        while not self.stopped.wait(seconds):
            with self.lock:
                if time.monotonic() - self.last >= seconds:
                    self.emit()

    def suffix(self):
        """' elapsed .. eta ..' for a tool that prints its own line per item ('' when off)."""
        if not self.active or not self.count:
            return ''
        return f'  elapsed {clock(time.monotonic() - self.start)}  eta {self.eta()}'

    def done(self, summary=''):
        self.stopped.set()
        if self.active:
            print(f'[{self.label}] done in {clock(time.monotonic() - self.start)}' + (f': {summary}' if summary else ''), file=self.stream, flush=True)
