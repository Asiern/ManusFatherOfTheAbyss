#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/lcd.c ../src/main.c ../src/oscilator.c ../src/timers.c ../src/uart.c ../src/utils.c ../src/cn.c ../src/adc.c ../src/gpio.c ../src/ocpwm.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/1360937237/lcd.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/oscilator.o ${OBJECTDIR}/_ext/1360937237/timers.o ${OBJECTDIR}/_ext/1360937237/uart.o ${OBJECTDIR}/_ext/1360937237/utils.o ${OBJECTDIR}/_ext/1360937237/cn.o ${OBJECTDIR}/_ext/1360937237/adc.o ${OBJECTDIR}/_ext/1360937237/gpio.o ${OBJECTDIR}/_ext/1360937237/ocpwm.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/1360937237/lcd.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1360937237/oscilator.o.d ${OBJECTDIR}/_ext/1360937237/timers.o.d ${OBJECTDIR}/_ext/1360937237/uart.o.d ${OBJECTDIR}/_ext/1360937237/utils.o.d ${OBJECTDIR}/_ext/1360937237/cn.o.d ${OBJECTDIR}/_ext/1360937237/adc.o.d ${OBJECTDIR}/_ext/1360937237/gpio.o.d ${OBJECTDIR}/_ext/1360937237/ocpwm.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1360937237/lcd.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1360937237/oscilator.o ${OBJECTDIR}/_ext/1360937237/timers.o ${OBJECTDIR}/_ext/1360937237/uart.o ${OBJECTDIR}/_ext/1360937237/utils.o ${OBJECTDIR}/_ext/1360937237/cn.o ${OBJECTDIR}/_ext/1360937237/adc.o ${OBJECTDIR}/_ext/1360937237/gpio.o ${OBJECTDIR}/_ext/1360937237/ocpwm.o

# Source Files
SOURCEFILES=../src/lcd.c ../src/main.c ../src/oscilator.c ../src/timers.c ../src/uart.c ../src/utils.c ../src/cn.c ../src/adc.c ../src/gpio.c ../src/ocpwm.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24HJ256GP610A
MP_LINKER_FILE_OPTION=,--script=p24HJ256GP610A.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1360937237/lcd.o: ../src/lcd.c  .generated_files/flags/default/a96a3249845d7629a1d200241862e3dc70d93bbc .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lcd.c  -o ${OBJECTDIR}/_ext/1360937237/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/1ba66fa18eeb463fcaace67b672c40a36dd29e73 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/oscilator.o: ../src/oscilator.c  .generated_files/flags/default/785e0d49ea94b4feb5ddb64cff0dbce24618c28d .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/oscilator.c  -o ${OBJECTDIR}/_ext/1360937237/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/oscilator.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/timers.o: ../src/timers.c  .generated_files/flags/default/1639041cba4f750f2326c0e4ac907e8048a530be .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/timers.c  -o ${OBJECTDIR}/_ext/1360937237/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/uart.o: ../src/uart.c  .generated_files/flags/default/36172201b07fa3a10447d8ebeaabb3be4cbfd79b .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/uart.c  -o ${OBJECTDIR}/_ext/1360937237/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/utils.o: ../src/utils.c  .generated_files/flags/default/84f78e2aa0fca908b9be34f98661e277daaf79d3 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils.c  -o ${OBJECTDIR}/_ext/1360937237/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/utils.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/cn.o: ../src/cn.c  .generated_files/flags/default/f965cbbca83adf89f113d13dd875a53f06ed3293 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/cn.c  -o ${OBJECTDIR}/_ext/1360937237/cn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cn.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/adc.o: ../src/adc.c  .generated_files/flags/default/322d2cdf158e6ec74fbfe11e2768e4fd01338bed .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/adc.c  -o ${OBJECTDIR}/_ext/1360937237/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/gpio.o: ../src/gpio.c  .generated_files/flags/default/51281b17fe7131f3fe4ee809ff7e363d0a63a743 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gpio.c  -o ${OBJECTDIR}/_ext/1360937237/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gpio.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/ocpwm.o: ../src/ocpwm.c  .generated_files/flags/default/188909b36a9c4709a91830ddcd601f1750400443 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ocpwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ocpwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/ocpwm.c  -o ${OBJECTDIR}/_ext/1360937237/ocpwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ocpwm.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1    -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
else
${OBJECTDIR}/_ext/1360937237/lcd.o: ../src/lcd.c  .generated_files/flags/default/529b63ff2d0596b902a9baa8cc1af3ccc2c7698d .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcd.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/lcd.c  -o ${OBJECTDIR}/_ext/1360937237/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/lcd.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  .generated_files/flags/default/e8fc558d9c0c4d958780b3c0318397c5d3a272f0 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/main.c  -o ${OBJECTDIR}/_ext/1360937237/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/oscilator.o: ../src/oscilator.c  .generated_files/flags/default/8389af7621738b58acc00f70ffb0deb52647ca46 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/oscilator.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/oscilator.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/oscilator.c  -o ${OBJECTDIR}/_ext/1360937237/oscilator.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/oscilator.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/timers.o: ../src/timers.c  .generated_files/flags/default/50c77f23850851e3b0847ca559896a65175a8250 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timers.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/timers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/timers.c  -o ${OBJECTDIR}/_ext/1360937237/timers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/timers.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/uart.o: ../src/uart.c  .generated_files/flags/default/716fb0dcf783cf7a30f08d4675ce98486e9e0797 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/uart.c  -o ${OBJECTDIR}/_ext/1360937237/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/uart.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/utils.o: ../src/utils.c  .generated_files/flags/default/1f9b2f557f9964393fa512a86ff832fe62fb13b2 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/utils.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/utils.c  -o ${OBJECTDIR}/_ext/1360937237/utils.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/utils.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/cn.o: ../src/cn.c  .generated_files/flags/default/8e0c48f69360b5a4b186106bf0aa9097ebcf435 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cn.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/cn.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/cn.c  -o ${OBJECTDIR}/_ext/1360937237/cn.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/cn.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/adc.o: ../src/adc.c  .generated_files/flags/default/dc3e719e9f933daf3a72e41523cc666d8e806f3c .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/adc.c  -o ${OBJECTDIR}/_ext/1360937237/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/adc.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/gpio.o: ../src/gpio.c  .generated_files/flags/default/a69e555d0b0e50f3b48fcf02f0307806b740f614 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/gpio.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/gpio.c  -o ${OBJECTDIR}/_ext/1360937237/gpio.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/gpio.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
${OBJECTDIR}/_ext/1360937237/ocpwm.o: ../src/ocpwm.c  .generated_files/flags/default/7c318eae2c7a5f79facdda020f36f60be1fdb979 .generated_files/flags/default/716777ebcf750942ef63bc8419a4009c63f8f531
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ocpwm.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/ocpwm.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../src/ocpwm.c  -o ${OBJECTDIR}/_ext/1360937237/ocpwm.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/_ext/1360937237/ocpwm.o.d"        -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -I"../../../../opt/microchip/xc16/v1.36/support/PIC24H/h" -I"../include" -msmart-io=1 -Wall -msfr-warn=off   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	
else
${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/ManusFatherOfTheAbyss.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
