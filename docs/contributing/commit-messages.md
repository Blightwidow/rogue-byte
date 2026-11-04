# Commit messages

[Conventional Commits](https://www.conventionalcommits.org/), as in sly1-decomp and OpenRAC:

```
type(scope): short summary

What changed and why, wrapped at 72 columns, and what you verified.
```

`scripts/commit_msg.py` checks the subject and the body wrap (the `commit-msg` hook of `.pre-commit-config.yaml`, or `make commits` over a
branch). CI does not run it, as in sly1-decomp.

- **Types**: `feat`, `fix`, `docs`, `refactor`, `perf`, `test`, `build`, `ci`, `chore` (regenerated files, imports), `style`
  (formatting only), `revert`.
- **Scopes** (optional): a part (`tools`, `config`, `docs`, `policy`, `progress`, `names`, `matching`) or a version (`us`, `eu`).
  Narrower is fine (`us/splat`).
- **The summary** says what the change does or what is now true, in lower case, without a full stop, at most 120 characters.
- **The body** is prose wrapped at 72 columns: what changed, why, and what you ran to verify it, with what it printed. New numbers
  (names recovered, matched count) go here.
- **One logical change per commit**, each leaving the tools and checks working. Large regenerated output goes in its own commit.
- **No attribution lines**: no `Co-authored-by:` or other trailers for AI tools.

```
fix(tools): read the Mode 1 sectors of a raw CD image
feat(us): 1CBB58 exact match
chore(progress): regenerate site data after elf
```

Never commit game data: executables, disc images, Ghidra projects, decompiler output (`.gitignore` lists what stays local).
