################################################################################
######################### User configurable parameters #########################
# filename extensions
CEXTS:=c
ASMEXTS:=s S
CXXEXTS:=cpp c++ cc

# probably shouldn't modify these, but you may need them below
ROOT=.
FWDIR:=$(ROOT)/firmware
BINDIR=$(ROOT)/bin
SRCDIR=$(ROOT)/src
INCDIR=$(ROOT)/include

WARNFLAGS+=
EXTRA_CFLAGS=
EXTRA_CXXFLAGS=

# Set to 1 to enable hot/cold linking
USE_PACKAGE:=1

# Add libraries you do not wish to include in the cold image here
# EXCLUDE_COLD_LIBRARIES:= $(FWDIR)/your_library.a
EXCLUDE_COLD_LIBRARIES:= 

# Set this to 1 to add additional rules to compile your project as a PROS library template
IS_LIBRARY:=0
# TODO: CHANGE THIS!
LIBNAME:=libbest
VERSION:=1.0.0
# EXCLUDE_SRC_FROM_LIB= $(SRCDIR)/unpublishedfile.c
# this line excludes opcontrol.c and similar files
EXCLUDE_SRC_FROM_LIB+=$(foreach file, $(SRCDIR)/main,$(foreach cext,$(CEXTS),$(file).$(cext)) $(foreach cxxext,$(CXXEXTS),$(file).$(cxxext)))

# Add subsystem source files
SUBSYSTEMS_SRC:= \
    $(SRCDIR)/subsystems/drivetrain.cpp \
    $(SRCDIR)/subsystems/wall.cpp \
    $(SRCDIR)/subsystems/roller.cpp \
    $(SRCDIR)/subsystems/intake.cpp \
    $(SRCDIR)/subsystems/pneumatics.cpp

# Include all source files except those excluded
SRCS:= $(wildcard $(SRCDIR)/*.[cC][pP][pP]) $(SUBSYSTEMS_SRC)

# Object files
OBJS:= $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRCS))

# Compiler and linker settings
CXX = arm-none-eabi-g++
CXXFLAGS += -std=gnu++20 -O2 $(WARNFLAGS) $(EXTRA_CXXFLAGS)
LDFLAGS += -T $(FWDIR)/v5.ld -Wl,--gc-sections

# Default target
all: $(BINDIR)/monolith.bin

# Compilation rule
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Linking rule
$(BINDIR)/monolith.bin: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -rf $(BINDIR)/*.o $(BINDIR)/monolith.bin

.PHONY: all clean