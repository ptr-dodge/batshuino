#include <Keyboard.h>

int delayAmount = 600;

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void doCommand(char command[])
{
  Keyboard.print(command);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(delayAmount);
}

void opencmd()
{
  typeKey(KEY_ESC);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  Keyboard.releaseAll();
  delay(delayAmount);
  Keyboard.print("cmd");
  delay(delayAmount);
  typeKey(KEY_RETURN);
  delay(delayAmount);
  doCommand("@echo off");
  doCommand("setlocal EnableDelayedExpansion");
  doCommand("setlocal EnableExtensions");
  doCommand("");
  doCommand("rem Function call");
  doCommand("set _1=World");
  doCommand("set _0=Hello");
  doCommand("call :func1 _7 0 _0 _1");
  doCommand("echo | set /p ^=!_7!");
  doCommand("rem Global and local variables");
  doCommand("set v1=Global V1");
  doCommand("set v2=Global V2");
  doCommand("set v3=Global V3");
  doCommand("set _2=Var");
  doCommand("call :func2 _8 0 _2");
  doCommand("echo | set /p ^=!_8!");
  doCommand("echo !v1!");
  doCommand("echo !v3!");
  doCommand("rem Return value");
  doCommand("set /a _3=4");
  doCommand("call :func3 _9 0 _3");
  doCommand("echo | set /p ^=!_9!");
  doCommand("echo:");
  doCommand("set /a _4=1");
  doCommand("call :func3 _10 0 _4");
  doCommand("set ret=!_10!");
  doCommand("echo Returned: !ret!");
  doCommand("rem Argument containing space");
  doCommand("set _5=Param with space");
  doCommand("call :f _11 0 _5");
  doCommand("set test=!_11!");
  doCommand("echo !test!");
  doCommand("rem List files");
  doCommand("for /f \"delims=\" %%i in ('dir /w') do set files=%%i");
  doCommand("rem Test existence");
  doCommand("if exist file1.txt (");
  doCommand("  echo file1.txt exists.");
  doCommand(")");
  doCommand("if exist file2.txt (");
  doCommand("  set /a existence=1");
  doCommand(") else (");
  doCommand("  set /a existence=0");
  doCommand(")");
  doCommand("if !existence! EQU 1 (");
  doCommand("  echo file2.txt exists.");
  doCommand(")");
  doCommand("if exist file3.txt (");
  doCommand("  set /a _6=1");
  doCommand(") else (");
  doCommand("  set /a _6=0");
  doCommand(")");
  doCommand("if !_6! NEQ 1 (");
  doCommand("  echo file3.txt does not exist.");
  doCommand(")");
  doCommand("");
  doCommand("goto :EOF");
  doCommand(":func1");
  doCommand("set p1_%~2=!%~3!");
  doCommand("set p2_%~2=!%~4!");
  doCommand("echo !p1_%~2! !p2_%~2!");
  doCommand("");
  doCommand("goto :EOF");
  doCommand(":func2");
  doCommand("set p_%~2=!%~3!");
  doCommand("set v1_%~2=Local !p_%~2!");
  doCommand("echo !v1_%~2!");
  doCommand("echo !v2!");
  doCommand("set v3=V3 Modified.");
  doCommand("");
  doCommand("goto :EOF");
  doCommand(":func3");
  doCommand("set num_%~2=!%~3!");
  doCommand("set /a _0_%~2=^(!num_%~2! + 41^)");
  doCommand("set %~1=!_0_%~2!");
  doCommand("goto :EOF");
  doCommand("");
  doCommand("goto :EOF");
  doCommand(":g");
  doCommand("set text_%~2=!%~3!");
  doCommand("set %~1=!text_%~2!");
  doCommand("goto :EOF");
  doCommand("");
  doCommand("goto :EOF");
  doCommand(":f");
  doCommand("set text_%~2=!%~3!");
  doCommand("set _0_%~2=!text_%~2!");
  doCommand("set /a _2_%~2=^(1 + %~2^)");
  doCommand("call :g _3_%~2 !_2_%~2! _0_%~2");
  doCommand("set _1_%~2=!_3_%~2!");
  doCommand("set %~1=!_1_%~2!");
  doCommand("goto :EOF");
  doCommand("exit");
}

void setup()
{
  Keyboard.begin();
  delay(1000);
  opencmd();
}

void loop() {}
