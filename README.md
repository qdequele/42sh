#Features :

X : Todo
O : Done
F : Need Fix

prototype : - X : blabla (username)

##Line Edition

###Mandatory

- O : Show prompt (qdequele)
- O : add one char (qdequele)
- O : del one char (qdequele)
- O : move to left (qdequele)
- O : move to right (qdequele)
- O : History (eebersol)
- X : Copy/Past/Cut (eebersol)
- O : move word left alt+left (qdequele)
- O : move word right alt+right (qdequele)
- O : move start fn+left | home (qdequele)
- O : move end fn+right | end (qdequele)
- O : move up alt+up (qdequele)
- O : move down alt+down (qdequele)
- X : quotes " ' (eebersol)
- 0 : Good implementation of tab or spaces (qdequele)

###Bonus

- X : history search builtins history | ctrl+R (eebersol)
- X : autocomplete (gbourson)
- O : Move max top (qdequele)
- O : Move max bottom (qdequele)

##Command execution

###Mandatory

- O : Line separator ; (qdequele)
- X : pipes | ()
- X : redirect << < >> > ()
- X : file descriptor agregator 2>&- ()
- X : Catch execution return number $? ()
- X : Logic operation || && ()

###Bonus

- X : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash) ()
- X : heredoc << ()
- X : back quotes ` ()
- X : sub shells () ()
- X : local varaibles unset export ()
- X : Job controls job / fg / bg / & ()
- X : Shell script ()

##Builtins

###Mandatory

- O : cd (qdequele)
- O : echo (eebersol)
- O : exit (qdequele)
- O : env (qdequele)
- O : setenv (qdequele)
- O : unsetenv (qdequele)

###Bonus

- O : History (eebersol)
- X : Read ()

#Liste des bugs :

- Executer une ligne de commande avec des tabs dedans puis executer ue ligne de commande quelconque == segfault;
- home ne vas pas à la bonne destination la premiere fois
-multi-ligne sur paste.