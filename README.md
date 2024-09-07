# State Machine C Template

This project provides a basic boilerplate for modeling a state machine in C. It
consists of just one source file, designed to be a starting point for
implementing state machines.

## Compiling

This projects compiles as a normal c program with just:

```bash
gcc statemachine.c -o statemachine
```

I would recommend to enable all warnings with -Wall and -Wextra
and also enable 2 warnings as errors:

* implicit-fallthrough:
  used to catch potential bugs in switch statements where one case might "fall
  through" into the next case unintentionally.
  It may be usefull also to just keep it as warning so for example we can
  handle 2 states/events the same way if we wanted, using implicit fallthrough
  trhough switch statements.

* switch:
  used to catch incompleted switch statements, making sure every state and
  transition are handled properly.

```bash
gcc statemachine.c -o statemachine -Wall -Wextra -Werror=implicit-fallthrought -Werror=switch
```
