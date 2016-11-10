#Features :

X : Todo
O : Done
F : Need Fix
I : Impossible
L : Leaks

prototype : - X : blabla (username)

##Line Edition

###Mandatory

- O : Show prompt
- O : add one char
- O : del one char
- O : move to left
- O : move to right
- O : History
- O : Copy/Past/Cut
- O : move word left alt+left
- O : move word right alt+right
- O : move start fn+left | home
- O : move end fn+right | end
- O : move up alt+up
- O : move down alt+down
- O : quotes " ' ` ()
- O : Good implementation of tab or spaces

###Bonus

- O : history search builtins history | ctrl+R
- O : autocomplete
- O : Move max top
- O : Move max bottom
- O : Operator || and &&

##Command execution

###Mandatory

- O : Line separator ;
- O : pipes |
- O : redirect  < >> >
- O : file descriptor agregator 2>&-
- O : Catch execution return number $?
- O : Logic operation || &&
- O : ctrl+c didn't quit the shell
- O : double ctrl+d quit the shell

###Bonus

- O : heredoc <<
- O : inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash)
- O : local varaibles unset export $
- L : Job controls job / fg / bg / &

##Builtins

###Mandatory

- O : cd
- O : echo
- O : exit
- O : env
- O : setenv
- O : unsetenv
- O : set
- O : unset
- O : export
- O : readonly
- O : unreadonly

###Bonus

- O : History
- O : Read

##General

- X : Leaks
- O : Norme
- X : Segfaut
- O : Signals
- X : Builtins Posix

#Liste des bugs :

* Cannot redirect builtins
* Copy / Paste is totally dafuq and not working well
* ls qweeq 2> toto; pwd >> toto | cat -e > lol | pwd n'est pas dans toto