#List of bugs :

##LEAKS

##SIGABORT

##SIGSEGV

##BUGS

##INPROVEMENT

- cat ressources/help.txt | head -c 300 | cat -e not have a cariage return
- set key -> wrong message
- readonly/unreadonly/unset/unsetenv - better message for not found
- echo "'" should print '
- echo '"'' should print "
- \ should avoid next char or write on multi line
- cat << -> 42sh: syntax error near unexpected token `newline'
