# Rogue Byte: decompilation tooling for Sly 2 (PS2, USA). No game data in this repository.
#
# Setup: ./setup.sh --sly2 /path/to/SCUS_973.16, then `make elf`; names: docs/build/name-recovery.md.

.PHONY: help elf objdiff config nonmatching src progress check test unit lint lint-shell compile-scripts links rules permute permute-stores fix-stack mutate adopt search land

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

objdiff: ## After `make elf`: objdiff.json, the objects it compares (matched functions and the non-matching sources) and site/data/objdiff-report.json
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

search: ## Everything in order: fix-stack, permute-stores, adopt, rules (MIN, MAX, BUDGET, JOBS apply); then register matches with try.py --record
	$(MAKE) fix-stack
	$(MAKE) permute-stores
	$(MAKE) adopt
	$(MAKE) rules

land: ## After a search or a matching round: register the matches (stops on a banned construct: FORCE=1 skips that), publish src/, the byte gate, then the reports and nonmatching/
	.venv/bin/python scripts/matching/record.py --jobs $(JOBS) $(if $(FORCE),--no-scan)
	$(MAKE) src
	$(MAKE) elf
	$(MAKE) progress
	$(MAKE) nonmatching
	$(MAKE) objdiff
	$(MAKE) progress

config: ## Regenerate config/us/sly2.us.yaml and pieces.tsv: one unit per module for code, rodata and data
	python3 -I scripts/build/gen_splat_config.py --reset
	.venv/bin/python configure.py --split
	python3 -I scripts/build/gen_splat_config.py --pieces
	.venv/bin/python configure.py --split

nonmatching: ## Publish the best compiling source of every unmatched function into nonmatching/ (slow: scores each candidate)
	python3 -I scripts/matching/export_nonmatching.py

src: ## Publish the matched functions from data/matching/src into src/
	python3 -I scripts/matching/export_src.py

progress: ## After `make elf`: the report, the Naming Desk data, the map and the site assets in site/
	.venv/bin/python scripts/gen_progress_report.py
	.venv/bin/python scripts/gen_context.py
	.venv/bin/python scripts/generate_treemap.py
	.venv/bin/python scripts/build_site.py

check: compile-scripts lint lint-shell links test ## The public CI checks, locally

lint: ## ruff: syntax errors and undefined names in the scripts
	.venv/bin/ruff check .

test: ## Regression tests of the scripts
	.venv/bin/python -I scripts/test_public_tools.py

unit: ## After `make elf`: do the matched functions of UNIT (module, address or src file; default all) link from C?
	.venv/bin/python scripts/check_unit.py $(UNIT)

compile-scripts: ## Byte-compile every Python script
	python3 -I -m compileall -q scripts

lint-shell: ## shellcheck, errors only
	shellcheck --severity=error setup.sh $$(git ls-files 'scripts/*.sh')

links: ## Relative links in the markdown files resolve
	python3 -I scripts/check_links.py
