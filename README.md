#Features :

X : Todo
O : Done
F : Need Fix
I : Impossible
L : Leaks

prototype : - X : blabla (username)

##Line Edition

###Mandatory

- O : Show prompt (qdequele)
- O : add one char (qdequele)
- O : del one char (qdequele)
- O : move to left (qdequele)
- O : move to right (qdequele)
- O : History (eebersol)
- O : Copy/Past/Cut (eebersol)
- O : move word left alt+left (qdequele)
- O : move word right alt+right (qdequele)
- O : move start fn+left | home (qdequele)
- O : move end fn+right | end (qdequele)
- O : move up alt+up (qdequele)
- O : move down alt+down (qdequele)
- O : quotes " ' ` () (eebersol + qdequele)
- O : Good implementation of tab or spaces (qdequele)

###Bonus

- O : history search builtins history | ctrl+R (eebersol)
- O : autocomplete (qdequele)
- O : Move max top (qdequele)
- O : Move max bottom (qdequele)
- O : Operator || and && (qdequele)

##Command execution

###Mandatory

- O : Line separator ; (qdequele)
- O : pipes | (eebersol + qdequele)
- O : redirect  < >> > (eebersol + qdequele)
- O : file descriptor agregator 2>&- (eebersol + qdequele)
- O : Catch execution return number $? (qdequele)
- O : Logic operation || && (qdequele)
- X : ctrl+c didn't quit the shell (qdequele)
- O : double ctrl+d quit the shell (qdequele)

###Bonus

- O : heredoc << (eebersol + qdequele)
- O : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash) (eebersol + qdequele)
- O : local varaibles unset export $ (qdequele)
- L : Job controls job / fg / bg / & (qdequele)

##Builtins

###Mandatory

- O : cd (qdequele)
- O : echo (eebersol)
- O : exit (qdequele)
- O : env (qdequele)
- O : setenv (qdequele)
- O : unsetenv (qdequele)
- O : set (qdequele)
- O : unset (qdequele)
- O : export (qdequele)
- O : readonly (qdequele)
- O : unreadonly (qdequele)

###Bonus

- O : History (eebersol)
- O : Read (eebersol)

##General

- X : Leaks
- X : Norme
- X : Segfaut
- X : Signals
- X : Builtins Posix

#Liste des bugs :

- echo toto tata titi" -> pointer being freed was not allocated
- << -> pointer being freed was not allocated
- echo `$?` -> segfault //backquote
- !7 -> 42sh: command not found: !7
- read toto
Read>titi -> set: Too many arguments.
