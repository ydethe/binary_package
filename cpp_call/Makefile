Q=@

.PHONY: default run

default: test.exe

test.exe: main.o
	$(Q)g++ -o $@ $< ../.venv/lib/python3.8/site-packages/talismans/hello.*.so -lpython3.8

main.o: main.cpp
	$(Q)g++ -c $< -o $@

run: test.exe
	$(Q)./test.exe
