#List of bugs :

##LEAKS

##SIGABORT

##SIGSEGV

##BUGS

- echo "'" should print '
- echo '"'' should print "
- cat << -> 42sh: syntax error near unexpected token `newline'
-  cat ||| test should be an error
-  cat &&& test should be an error

##INPROVEMENT

- readonly/unreadonly/unset/unsetenv - better message for not found
- \ should avoid next char or write on multi line


