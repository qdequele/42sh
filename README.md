#Features :

X : Todo
O : Done
F : Need Fix
I : Impossible

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
- F : quotes " ' ` () (eebersol + qdequele)
- 0 : Good implementation of tab or spaces (qdequele)

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
- X : double ctrl+d quit the shell (qdequele)

###Bonus

- O : heredoc << (eebersol + qdequele)
- F : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash) (eebersol + qdequele)
- F : local varaibles unset export $ (qdequele)
- X : Job controls job / fg / bg / & (qdequele)

##Builtins

###Mandatory

- O : cd (qdequele)
- F : echo (eebersol)
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

- Executer une ligne de commande avec des tabs dedans puis executer ue ligne de commande quelconque == segfault;
- home ne vas pas à la bonne destination la premiere fois
- pb builtin_cd ne marche pas
