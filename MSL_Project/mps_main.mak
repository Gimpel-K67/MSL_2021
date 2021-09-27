# TASKING EDE (Windows based integrated Embedded Development Environment)
#
# This makefile has been generated by TASKING EDE
#
# Toolchain: TASKING Tools for C166/ST10 v8.7 r1
#

PROJ    = mps_main
PROJDIR = c:\users\mikropro2021\documents\github\msl_2021\msl_project
PRODDIR = d:\programme\tasking\c166 v8.7r1

BINDIR  = $(PRODDIR)\bin
INCDIR  = $(PRODDIR)\include
LIBDIR  = $(PRODDIR)\lib

CC166BIN = $(PRODDIR)\bin
	export CC166BIN

OPT_CC  = -Wcp-D_USMLIB=  -Wcp"-I$(PRODDIR)\include" -Ms -Wc"-I$(PRODDIR)\include" -Wc-x2 -Wc-Bhoeufmknladij          -Wc-OB -Wc-OE -Wc-zswitch_tabmem_default -Wc-zautobitastruct-4 -Wc-zautobita-0 -FSC -noc++ -Wc-A1 -Wc-zvolatile_union -Wc-O0 -Wc-g -Wc-newerr -Wc-s -tmp -Wc-i0 "-WaPR($*.lst)" -WaPL(60) -WaPW(120) -WaTA(8) -WaWA(1) -WaNOM166 -WaSN(regxe167f.def) -WaEXTEND2 -WmDEF(_EXT,1) -WmDEF(_EXT2,1) -WmDEF(_EXT22,0) -WmDEF(_EXTMAC,1) -WmDEF(MODEL,SMALL) -WmDEF(_USRSTACK,0) -WmDEF(_SINGLE_FP,0) -WmWA(1) -WmINC('$(PRODDIR)\include')
OPT_LC  = -trap -libfmtiol -WoPRINT("mps_main.map") -Ms -x2 EXTEND2 -Bhoeufmknladij  -cf "c:\users\mikropro2021\documents\github\msl_2021\msl_project\_mps_main.ilo"
OPT_OPI3E = -s0xC00000  -v2
OPT_XVW = -G "." -tcfg "c:\users\mikropro2021\documents\github\msl_2021\msl_project\_mps_main.cfg" -D TCP,localhost,1 --single_instance --load_application_download=true --load_application_verify=true --enable_flash=true --load_application_use_map_file=true --load_application_signal=true --load_application_program_reset=true --load_application_target_reset=true --load_application_goto_main=true --load_application_break_on_exit=true -i -a 100 -b 200 -s 26

all : subproj $(PROJ).abs

subproj :
	@echo Warning: Infinite loop detected; Not building sub-project mps_main.pjt

ccu63.obj : ccu63.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
ccu63.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c ccu63.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

io.obj : io.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c io.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

main.obj : main.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
main.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c main.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

scs.obj : scs.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
scs.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c scs.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

start_master.obj : start_master.asm "$(PRODDIR)\include\head.asm" "$(PRODDIR)\include\_c_init.asm" <1632321531>
	@echo Preprocessing ${*F}.asm
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c start_master.asm
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

gpt1.obj : gpt1.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
gpt1.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c gpt1.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

gpt2.obj : gpt2.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
gpt2.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c gpt2.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

cc2.obj : cc2.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
cc2.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c cc2.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

ccu62.obj : ccu62.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
ccu62.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c ccu62.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

adc0.obj : adc0.c main.h xe16xregs.h scs.h io.h gpt1.h gpt2.h cc2.h ccu62.h ccu63.h
adc0.obj : adc0.h <1632742349>

	@echo Compiling and assembling ${*F}.c
	@"$(PRODDIR)\bin\cc166.exe" -f <<EOF -c adc0.c
	${separate "\n" -o $@ $(OPT_CC) }
	EOF

$(PROJ).out : ccu63.obj io.obj main.obj scs.obj start_master.obj gpt1.obj gpt2.obj
$(PROJ).out : cc2.obj ccu62.obj adc0.obj _mps_main.ilo <1632742349>
	@echo Linking and locating to ${*F}.out
	@"$(PRODDIR)\bin\cc166.exe" $(LINKCPP) -o $@ -f <<EOF 
	${separate "\n" $(match .obj $!) $(match .lno $!) $(match .lib $!) $(OPT_LC)}
	EOF

$(PROJ).abs : $(PROJ).out <1632321531>
	@echo Converting ${*F}.out to ${*F}.abs in IEEE-695 format
	@"$(PRODDIR)\bin\ieee166.exe" $(OPT_OPI3E) $! $@

clean :
	@echo Deleting intermediate files and output files for project '$(PROJ)'.
	@$(exist ccu63.obj del ccu63.obj)
	@$(exist ccu63.src del ccu63.src)
	@$(exist ccu63.lst del ccu63.lst)
	@$(exist io.obj del io.obj)
	@$(exist io.src del io.src)
	@$(exist io.lst del io.lst)
	@$(exist main.obj del main.obj)
	@$(exist main.src del main.src)
	@$(exist main.lst del main.lst)
	@$(exist scs.obj del scs.obj)
	@$(exist scs.src del scs.src)
	@$(exist scs.lst del scs.lst)
	@$(exist start_master.obj del start_master.obj)
	@$(exist start_master.src del start_master.src)
	@$(exist start_master.lst del start_master.lst)
	@$(exist gpt1.obj del gpt1.obj)
	@$(exist gpt1.src del gpt1.src)
	@$(exist gpt1.lst del gpt1.lst)
	@$(exist gpt2.obj del gpt2.obj)
	@$(exist gpt2.src del gpt2.src)
	@$(exist gpt2.lst del gpt2.lst)
	@$(exist cc2.obj del cc2.obj)
	@$(exist cc2.src del cc2.src)
	@$(exist cc2.lst del cc2.lst)
	@$(exist ccu62.obj del ccu62.obj)
	@$(exist ccu62.src del ccu62.src)
	@$(exist ccu62.lst del ccu62.lst)
	@$(exist adc0.obj del adc0.obj)
	@$(exist adc0.src del adc0.src)
	@$(exist adc0.lst del adc0.lst)
	@$(exist $(PROJ).out del $(PROJ).out)
	@$(exist mps_main.map del mps_main.map)
	@$(exist $(PROJ).abs del $(PROJ).abs)

# Copyright 1997-2007 Altium BV
# Serial#:	000000
# EDE Version:	99.9r9 (Build 150)
