# Security

Rogue Byte is a set of build and analysis scripts, a downloaded toolchain and reconstructed code. It has no service and no user
data. What can go wrong is:

- a script or a workflow that runs code it should not (a pull request that reaches a secret or a write token),
- a download in `setup.sh` that is not what it should be (every archive is checked against a pinned SHA-256),
- game data or a proprietary file committed by mistake (see [CONTRIBUTING.md](CONTRIBUTING.md) and
  [docs/contributing/code-cleanup.md](docs/contributing/code-cleanup.md)).

Report any of them privately through GitHub's "Report a vulnerability" on the Security tab of this repository, or, if that is not
available, open an issue that says only that you have a report and ask for a contact. Please do not put an exploit or the
content of a leaked file in a public issue. A reply should come within a week.

Only the latest commit on `main` is supported.
