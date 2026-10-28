# Rogue Byte: decompilation tooling for Sly 2 (PS2, USA). No game data in this repository.
#
# Setup: ./setup.sh --sly2 /path/to/SCUS_973.16, then `make elf`; names: docs/build/name-recovery.md.

.PHONY: help elf objdiff config src progress check test unit lint lint-shell compile-scripts links

help: ## List the targets
	@grep -hE '^[a-z-]+:.*## ' $(MAKEFILE_LIST) | awk -F':.*## ' '{printf "  %-16s %s\n", $$1, $$2}'

.DEFAULT_GOAL := help

elf: ## Split the executable, rebuild it from asm and check it byte for byte (the gate)
	.venv/bin/python configure.py --split
	mkdir -p build/image
	.venv/bin/ninja -k 0 pieces units
	.venv/bin/python scripts/build/link_image.py
	.venv/bin/python scripts/build/pack_elf.py
	.venv/bin/python scripts/verify_image.py build/image/image.bin

objdiff: ## After `make elf`: objdiff.json, the objects it compares and site/data/objdiff-report.json
	.venv/bin/python scripts/build/make_objdiff.py

config: ## Regenerate config/us/sly2.us.yaml and pieces.tsv: one unit per module for code, rodata and data
	python3 -I scripts/build/gen_splat_config.py --reset
	.venv/bin/python configure.py --split
	python3 -I scripts/build/gen_splat_config.py --pieces
	.venv/bin/python configure.py --split

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
	python3 -I scripts/test_public_tools.py

unit: ## After `make elf`: do the matched functions of UNIT (module, address or src file; default all) link from C?
	.venv/bin/python scripts/check_unit.py $(UNIT)

compile-scripts: ## Byte-compile every Python script
	python3 -I -m compileall -q scripts

lint-shell: ## shellcheck, errors only
	shellcheck --severity=error setup.sh $$(git ls-files 'scripts/*.sh')

links: ## Relative links in the markdown files resolve
	python3 -I scripts/check_links.py
