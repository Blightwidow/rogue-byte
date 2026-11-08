# sly2-decomp: decompilation tooling for Sly 2 (PS2, USA). No game data in this repository.
#
# Setup: ./setup.sh --sly2 /path/to/SCUS_973.16, then `make elf`; names: docs/build/name-recovery.md.

 .PHONY: help elf objdiff blockers config nonmatching src report readme repo-check cleanup commits check test unit lint lint-shell compile-scripts links pal-check rules permute permute-stores fix-stack mutate adopt search land pal

help: ## List the targets
	@grep -hE '^[a-z-]+:.*## ' $(MAKEFILE_LIST) | awk -F':.*## ' '{printf "  %-16s %s\n", $$1, $$2}'

.DEFAULT_GOAL := help

# The long searches print a progress line (scripts/matching/progress.py) when started through make; PROGRESS=0 silences them
export PROGRESS ?= 1

elf: ## Split the executable, rebuild it from asm and check it byte for byte (the gate)
	.venv/bin/python configure.py --split
	mkdir -p build/image
	.venv/bin/ninja -k 0 pieces units
	.venv/bin/python scripts/build/link_image.py
	.venv/bin/python scripts/build/pack_elf.py
	.venv/bin/python scripts/verify_image.py build/image/image.bin
	.venv/bin/python scripts/vu/vuasm.py verify build/image/SCUS_973.16

objdiff: ## After `make elf`: objdiff.json, the objects it compares (matched functions and the non-matching sources) and progress/us/report.json
	.venv/bin/python configure.py
	.venv/bin/ninja -k 0 nonmatching
	.venv/bin/python scripts/build/make_objdiff.py

MIN ?= 1
MAX ?= 20
BUDGET ?= 800
JOBS ?= 8
rules: ## Try the deep-dive rewrites (scripts/matching/rules.py) and the neighborhood search on the near misses scoring MIN to MAX (default 1 to 20, BUDGET compiles each): a better source is written to data/matching/src/fn
	.venv/bin/python scripts/matching/neighborhood.py --batch --min-score $(MIN) --max-score $(MAX) --budget $(BUDGET) --jobs $(JOBS) --write

SEED ?= 1

permute: ## One function: reorder its statements (those marked //P first), ADDRESS=0x11A060 [SOURCE=file BUDGET=800]; a better source is written in place
	@test -n "$(ADDRESS)" || { echo "usage: make permute ADDRESS=0x11A060"; exit 2; }
	.venv/bin/python scripts/matching/permute.py $(ADDRESS) $(if $(SOURCE),$(SOURCE),data/matching/src/fn/$(shell .venv/bin/python -c "print('%06X' % int('$(ADDRESS)', 16))").cpp) --budget $(BUDGET) --jobs $(JOBS) --write

permute-stores: ## The store-order search over the near misses scoring MIN to MAX (writes to work/matching/permute-stores; `make adopt` takes the better ones)
	.venv/bin/python scripts/matching/permute_stores.py --min $(MIN) --max $(MAX) --budget $(BUDGET) --jobs $(JOBS) --seed $(SEED)

fix-stack: ## Size the placeholder sp[0x400] buffers of the near misses (writes to work/matching/fix-stack; `make adopt` takes the better ones)
	.venv/bin/python scripts/matching/fix_stack.py --jobs $(JOBS)

mutate: ## The random rewrites of mutate.py on the near misses scoring MIN to MAX; a better source is written to data/matching/src/fn
	.venv/bin/python scripts/matching/mutate.py --batch --min-score $(MIN) --max-score $(MAX) --budget $(BUDGET) --jobs $(JOBS) --write

adopt: ## Take the sources of work/matching/fix-stack and permute-stores that score strictly lower than the current ones into data/matching/src/fn
	.venv/bin/python scripts/matching/adopt.py

boundary-suspects: ## Near misses whose score is a split artifact (work/matching/boundary_suspects.tsv: the search tools skip them; fix them by hand with split_boundary.py or merges.tsv)
	.venv/bin/python scripts/matching/boundary_suspects.py --write

sigs: ## Return types of the callees of the near misses scoring MIN to MAX, read from the executable (callee_sigs.py sweep); a better source is written to data/matching/src/fn
	.venv/bin/python scripts/matching/callee_sigs.py build
	.venv/bin/python scripts/matching/callee_sigs.py sweep --min-score $(MIN) --max-score $(MAX) --jobs $(JOBS) --write

search: ## Everything in order: boundary-suspects, sigs, fix-stack, permute-stores, adopt, rules (MIN, MAX, BUDGET, JOBS apply); then register matches with try.py --record. A rewrite that adds a banned construct, a cleanup problem or a review warning is not written (search_guard.py); config/matching/walls.tsv lists what is left out
	$(MAKE) boundary-suspects
	$(MAKE) sigs
	$(MAKE) fix-stack
	$(MAKE) permute-stores
	$(MAKE) adopt
	$(MAKE) rules

land: ## After a search or a matching round (ONLY="0xADDR ..." registers just those, as claim.py land prints): register the matches (stops on a banned construct: FORCE=1 skips that), publish src/, the byte gate, then the reports (PAL too when its executable is there) and the README table and nonmatching/
	.venv/bin/python scripts/matching/record.py --jobs $(JOBS) $(if $(FORCE),--no-scan) $(if $(ONLY),--only $(ONLY))
	$(MAKE) src
	$(MAKE) elf
	$(MAKE) blockers
	$(MAKE) report
	$(MAKE) nonmatching
	$(MAKE) objdiff
	@if [ -f work/elf/SCES_525.29 ]; then $(MAKE) pal; else echo "no work/elf/SCES_525.29: PAL skipped"; fi
	$(MAKE) readme

pal: ## PAL (needs work/elf/SCES_525.29, see docs/build/building.md): pair the functions, check the matched ones, write progress/eu/report.json
	.venv/bin/python scripts/pair_versions.py
	.venv/bin/python scripts/version_check.py --jobs $(JOBS)
	.venv/bin/python scripts/pal_report.py

config: ## Regenerate config/us/sly2.us.yaml and pieces.tsv: one unit per module for code, rodata and data
	python3 -I scripts/build/gen_splat_config.py --reset
	.venv/bin/python configure.py --split
	python3 -I scripts/build/gen_splat_config.py --pieces
	.venv/bin/python configure.py --split

nonmatching: ## Publish the best compiling source of every unmatched function into nonmatching/ (slow: scores each candidate)
	python3 -I scripts/matching/export_nonmatching.py

src: ## Publish the matched functions from data/matching/src into src/
	python3 -I scripts/matching/export_src.py

blockers: ## After `make elf`: config/us/blockers.tsv, the permanent blockers (VU0, MMI, COP0, hand-written) that stay assembly (docs/build/vu0-mmi.md)
	python3 -I scripts/classify_blockers.py

report: ## After `make elf`: work/report.json (every function with its status, git-ignored), the input of `make nonmatching` and list_functions.py
	.venv/bin/python scripts/gen_progress_report.py

readme: ## Rewrite the progress table of README.md from progress/*/report.json
	python3 -I scripts/readme_progress.py

check: compile-scripts lint lint-shell links test repo-check pal-check cleanup commits ## The public CI checks, locally

# The base of the branch checks: origin/main when it exists, else main. A local main left behind by a squash merge would list the merged commits
# (and GitHub's Co-authored-by trailer on the squash commit) as this branch's own.
CHECK_BASE := $(or $(BASE),$(shell git rev-parse --verify -q origin/main >/dev/null 2>&1 && echo origin/main || echo main))

cleanup: ## The code-cleanup rules on what this branch adds to src/ and include/ (BASE=origin/main): docs/contributing/code-cleanup.md
	python3 -I scripts/check_cleanup.py --base $(CHECK_BASE)

commits: ## The commit messages of this branch against docs/contributing/commit-messages.md (BASE=origin/main)
	python3 -I scripts/commit_msg.py --range $(CHECK_BASE)..HEAD

repo-check: ## No game data or proprietary material, licence headers (tests/check_repository.py)
	python3 -I tests/check_repository.py

lint: ## ruff: syntax errors and undefined names in the scripts
	.venv/bin/ruff check .

pal-check: ## The committed PAL data is current: every matched function has a PAL status row, the PAL report matches (no executable needed)
	python3 -I scripts/pal_report.py --check

test: ## Regression tests of the scripts
	.venv/bin/python -m unittest discover -s tests

unit: ## After `make elf`: do the matched functions of UNIT (module, address or src file; default all) link from C?
	.venv/bin/python scripts/check_unit.py $(UNIT)

compile-scripts: ## Byte-compile every Python script
	python3 -I -m compileall -q scripts tests

lint-shell: ## shellcheck, errors only
	shellcheck --severity=error setup.sh $$(git ls-files 'scripts/*.sh')

links: ## Relative links in the markdown files resolve
	python3 -I scripts/check_links.py
