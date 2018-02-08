# Multithreaded Kernel with Time Sharing

## What is it about? ##

- Providing environment for multhithreading programming, similar to Java.
- A programmer can develop programs that have multiple threads.
To do so, the programmer needs the implement a class that extends class Thread and implement the run() method of it.
Programmer can say t.waitToComplete(), meaning the current thread needs to wait for thread t to finich before it can proceed.
- Thread can also be blocked on event, not only other thread.
Event is connected to the interrupt routine (for keyboard, mouse, etc)
Programmer can say event.wait() in the running thread.
Once the event has occured, all threads waiting on it can continue (are unblocked).

API: 
- Class Thread: 
  - start() 
  - waitToComplete()
  - run() - to implement! (virtual)

- Class Event: 
  - Event(ivtNo - number of the interrupt routine, keyboard, mouse etc)
  - wait()

## How is it implemented? ##
This project was implemented in C++. To compile, please use Turbo C.
