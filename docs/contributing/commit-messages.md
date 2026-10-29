# Commit messages

One shape: `<type>: <summary>`, lowercase type, imperative summary, no trailing period, at most 120 characters.
One commit, one primary area. `scripts/commit_msg.py` checks this (the `commit-msg` hook of `.pre-commit-config.yaml` and the `checks` workflow on pull requests).

| Type | Use for |
| :--- | :--- |
| `names` | Name and type recovery: matcher passes, name merges, signatures, struct layouts |
| `decomp` | Decompilation and matching work, its tooling and results |
| `build` | The build: `configure.py`, `scripts/build/`, the Makefile, `setup.sh` |
| `ci` | Workflows, hooks and the checks they run |
| `docs` | README, CONTRIBUTING, logs, reviews, the progress page |
| `chore` | Cleanup, generated data refreshes, dotfiles |
| `fix` | A bug in a script |

Put the new numbers (names recovered, matched share) in the body or in the matching log. Never commit game data:
executables, disc images, Ghidra projects, decompiler output (`.gitignore` lists what stays local).
No `Co-authored-by:` or other attribution trailers for AI tools.
