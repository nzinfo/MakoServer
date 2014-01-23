
             Mako Server Source Code Release
                  http://makoserver.net/


1: License
2: The included files
3: Compiling the C code


1: ---- License:

The Mako Server uses two license types.

 * The Barracuda Application Server library is released under the
   terms of a non-commercial license.

 * All other software, including the Lua code is released under the
   terms of the MIT license.

Do not use the two source files barracuda.c and barracuda.h before
downloading and reading the non-commercial license agreement. The
license is available at the following URL:
http://makoserver.net/non-commercial-license.pdf

The license for all other software is available at the following URL:
http://opensource.org/licenses/mit-license.html


2: ---- The included files:

makefile     - Example makefile: includes cross compilation examples.

barracuda.c - Amalgamated and Obfuscated Barracuda Application Server
              (BAS) library. This amalgamated version of the BAS
              library is designed for Posix systems such as Linux and
              Mac. The code will not compile on Windows. See the
              following link for more information on the BAS library
              and other supported platforms, including RTOS ports:
              http://realtimelogic.com/products/barracuda-application-server/
MakoMain.c  - Mako Server is nothing more than startup code for BAS.
SendError.c - Sends a message on internal error, if enabled.

mako.zip    - Mako Server Lua startup scripts and auxiliary code.
LspZip.c    - Embedded smaller version of mako.zip.

sqlite3.c    - SQLite: SQL database engine.
ls_sqlite3.c - SQLite Lua bindings.
luasql.c     - Generic SQL Lua bindings.


3 ---- Compiling the C code:

Start a Linux command line shell and type 'make' in the directory
where you unpacked the files. This will build the Mako Server for your
native Linux platform.

Cross compiling (for embedded Linux):

The makefile includes a few example setups for cross compiling. As an
example, to cross compile for a MIPS based DD-WRT router, type the
following on the command line:

make DD_WRT=true MIPS=true

Note: you must edit the makefile and set the path to the cross
compiler before running the above build command.


3.1 ---- Smaller executable (Removing the embedded database):

You can remove SQLite and make the executable smaller if an integrated
database engine is not needed.

Disable SQLite as follows:
1: Delete the 3 database C files or modify the makefile so these files
   are not included in the build.
2: Open MakoMain.c in an editor, search for luaopen_SQL(L), and comment
   out the line.
3: Recompile the server.


