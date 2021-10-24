CC=cc
CXX=g++
DEFS=
FLAGS=-g -Wall -Wextra $(DEFS)
CFLAGS=$(FLAGS) -std=gnu17
CXXFLAGS=$(FLAGS) -std=gnu++17
LIBS=-pthread -lm
LINTFILTERS=$\
	-build/c++17,$\
	-build/header_guard,$\
	-build/include_subdir,$\
	-readability/casting,$\
	-runtime/references

APPNAME:=lab5
DIRS:=src
HEADERS:=$(wildcard $(DIRS:%=%/*.hpp))
SOURCES:=$(wildcard $(DIRS:%=%/*.cpp))
OBJECTS=$(SOURCES:src/%.c=build/%.o)
INCLUDES=$(DIRS:%=-I%)

.SECONDEXPANSION:

bin/$(APPNAME): $(OBJECTS) | $$(@D)/.
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@ $(LIBS)

build/%.o: src/%.c $(HEADERS) | $$(@D)/.
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) $< -o $@ $(LIBS)

.PRECIOUS: %/.
%/.:
	mkdir -p $(dir $@)

all: bin/$(APPNAME) sanitizers lint memcheck helgrind
sanitizers: bin/$(APPNAME)_asan bin/$(APPNAME)_msan bin/$(APPNAME)_tsan bin/$(APPNAME)_ubsan

bin/$(APPNAME)_asan: $(SOURCES)
	clang $(CFLAGS) $(INCLUDES) -fsanitize=address $^ -o $@ $(LIBS)

bin/$(APPNAME)_msan: $(SOURCES)
	clang $(CFLAGS) $(INCLUDES) -fsanitize=memory $^ -o $@ $(LIBS)

bin/$(APPNAME)_tsan: $(SOURCES)
	clang $(CFLAGS) $(INCLUDES) -fsanitize=thread $^ -o $@ $(LIBS)

bin/$(APPNAME)_ubsan: $(SOURCES)
	clang $(CFLAGS) $(INCLUDES) -fsanitize=undefined $^ -o $@ $(LIBS)

.PHONY: lint
lint:
	cpplint --filter=$(LINTFILTERS) $(HEADERS) $(SOURCES)

.PHONY: memcheck
memcheck:
	valgrind --tool=memcheck bin/$(APPNAME) $(APPARGS)

.PHONY: helgrind
helgrind:
	valgrind --quiet --tool=helgrind bin/$(APPNAME) $(APPARGS)

.PHONY: gitignore
gitignore:
	echo bin > .gitignore
	echo build >> .gitignore

.PHONY: clean
clean:
	rm -rf bin build
