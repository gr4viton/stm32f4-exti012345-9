##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2014 Frantisek Burian <BuFran@seznam.cz>
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.
##

###############################################################################
# The support makefile for GCC compiler toolchain, the rules part.
#
# please read mk/README for specification how to use this file in your project
#

%.bin: %.elf
	@$(PRINTF) "  OBJCOPY $@\n"
	$(Q)$(OBJCOPY) -Obinary $< $@

%.hex: %.elf
	@$(PRINTF) "  OBJCOPY $@\n"
	$(Q)$(OBJCOPY) -Oihex $< $@

%.srec: %.elf
	@$(PRINTF) "  OBJCOPY $@\n"
	$(Q)$(OBJCOPY) -Osrec $< $@

%.list: %.elf
	@$(PRINTF) "  OBJDUMP $@\n"
	$(Q)$(OBJDUMP) -S $< > $@

%.elf: $(OBJS) $(LDSCRIPT) $(LIBDEPS)
	@$(PRINTF) "  LD      $(*).elf\n"
	$(Q)$(LD) $(OBJS) $(LDLIBS) $(LDFLAGS) -T$(LDSCRIPT) $(ARCH_FLAGS)  -o $@


%.elf %.map: $(OBJS) $(LDSCRIPT) $(LIBDEPS)
	@$(PRINTF) "  LD      $(*).elf\n"
	@$(PRINTF) "  MAP     $(*).map\n"
	$(Q)$(LD) $(OBJS) $(LDLIBS) $(LDFLAGS) -Wl,-Map=$(*).map -T$(LDSCRIPT) $(ARCH_FLAGS)  -o $(*).elf

%.a: $(OBJS)
	@$(PRINTF) "  AR      $(@F)\n"
	$(Q)$(AR) $(ARFLAGS) $@ $(OBJS)

$(INTERMEDIATE_DIR)%.o: %.c $(INTERMEDIATE_DEP)
	@$(PRINTF) "  CC      $<\n"
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $@ -c $<

$(INTERMEDIATE_DIR)%.o: %.cxx $(INTERMEDIATE_DEP)
	@$(PRINTF) "  CXX     $<\n"
	$(Q)$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $@ -c $<

$(INTERMEDIATE_DIR)%.o: %.cpp $(INTERMEDIATE_DEP)
	@$(PRINTF) "  CXX     $(*).cpp\n"
	$(Q)$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(ARCH_FLAGS) -o $@ -c $<


.PHONY: clean
clean: clean-objs

.PHONY: clean-objs
clean-objs:
	@$(PRINTF) "  CLEAN   $@\n"
	-$(Q)$(RM) -rf $(INTERMEDIATE_DIR)*.o $(INTERMEDIATE_DIR)*.d $(INTERMEDIATE_DEP)
