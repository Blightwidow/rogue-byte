#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""progress.py - progress lines for the long searches, off unless PROGRESS=1.

`make` exports PROGRESS=1 (`make rules PROGRESS=0` turns it off again), so a person who starts a search through make sees where it is;
a tool run directly, by an agent or a script, prints exactly what it printed before. The lines go to stderr, so the totals a tool prints
on stdout stay as they were:

    [rules] 310/867 36%  elapsed 41m02s  eta 1h12m  1FC270: 6 -> 5

    progress = Progress(len(items), 'rules')
    for item in items:
        ...
        progress.tick('1FC270: 6 -> 5')     # at most one line every few seconds, and always the last
    progress.done()
"""
import os
import sys
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
    def __init__(self, total, label, interval=5.0, stream=None):
        self.total, self.label, self.interval = total, label, interval
        self.stream = stream or sys.stderr
        self.count, self.start, self.last = 0, time.monotonic(), 0.0
        self.active = enabled()

    def eta(self):
        """The time left, estimated from the average of what is done ('' before the first item)."""
        if not self.count:
            return ''
        elapsed = time.monotonic() - self.start
        return clock(elapsed / self.count * (self.total - self.count))

    def line(self, note=''):
        elapsed = clock(time.monotonic() - self.start)
        percent = 100 * self.count // self.total if self.total else 100
        text = f'[{self.label}] {self.count}/{self.total} {percent}%  elapsed {elapsed}'
        if self.count < self.total and self.eta():
            text += f'  eta {self.eta()}'
        return text + (f'  {note}' if note else '')

    def tick(self, note='', step=1):
        """One more item done; a line when the interval has passed since the last, and for the last item."""
        self.count += step
        if not self.active:
            return
        now = time.monotonic()
        if now - self.last >= self.interval or self.count >= self.total:
            self.last = now
            print(self.line(note), file=self.stream, flush=True)

    def suffix(self):
        """' elapsed .. eta ..' for a tool that prints its own line per item ('' when off)."""
        if not self.active or not self.count:
            return ''
        return f'  elapsed {clock(time.monotonic() - self.start)}  eta {self.eta()}'

    def done(self, summary=''):
        if self.active:
            print(f'[{self.label}] done in {clock(time.monotonic() - self.start)}' + (f': {summary}' if summary else ''), file=self.stream, flush=True)
