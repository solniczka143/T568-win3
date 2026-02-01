# Win16 T568 learning Windwos 3 aplication

## Introduction

Small application with learning t568 A/B wiring standard in mind.


## Building the Application

To build the application with the Microsoft Visual C++ 1.5x GUI, go to
"project", "open", then open "Win16App.mak". To choose a debug or release build,
go to "options" then "project". The project can be built using the "build" or
"rebuild" toolbar items, or via the "project" menu.

To build the application from the command line with Visual C++ 1.5x, launch a
command prompt, run the "MSVCVARS.BAT" file which can be found in the Visual C++
"bin" directory, and then navigate to the directory containing the Makefile. Run
"nmake /f Win16App.mak" to build. This also works with the Windows Server 2003
DDK, but instead of running "MSVCVARS.BAT", you will need to add the "bin16"
directory to your "%PATH%" environment variable, "inc16" to "%INCLUDE%", and
"lib16" to "%LIB%".

To build the application in [Open Watcom](http://openwatcom.org/), open the
project up in the IDE, and choose the "Make" option from the "Targets" menu. You
can switch between debug and release builds by going to "Targets", "Target
Options", and choosing "Use Development Switches" or "Use Release Switches".

## Smart Callbacks

This application makes use of so-called "smart callbacks". This means the data segment register is loaded from the
stack segment register on entry to any callback function which is called by Windows. The result of this is that it is
not necessary to list the callback functions in the application's module definition file, and it is not necessary to use
"MakeProcInstance" to create a thunk when (e.g.) displaying a dialog box. In Visual C++ this is achieved by marking
callback functions with the "__export" modifier, and using the "/GA /GEs /GEm" compiler options (optimise far function
epilogs, load DS from SS, and increment BP on entry to the callback--required only for real mode stack walking support).
You can also use the "/GEf" option, which means all far functions are given the code to load DS from SS regardless of
whether they are callback functions. This is slightly less efficient, but does mean that callback functions don't
require the "__export" modifier.

Open Watcom does the same thing, but uses the "-zWs" compiler option to include the segment loading code.

## Terms of Use

Refer to "License.txt" for terms of use.

## Known Problems

The Open Watcom build of the application doesn't work correctly under Windows
3.0 when running in Real Mode. The application will start but the menu is
missing and the about dialog won't display. I've found Open Watcom to be a bit
hit and miss, where certain seemingly harmless changes of compiler option result
in an application which crashes, so it may be possible to fix this by changing
the compiler options. It runs fine under Windows 3.0 in Standard Mode and 386
Enhanced Mode.

The Open Watcom build of the application has optimisations switched off. With
optimisations enabled, the application crashes on startup.
