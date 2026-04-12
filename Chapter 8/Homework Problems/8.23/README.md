Exercise 8.23
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
One of your colleagues is thinking of using signals to allow a parent process to count events that occur in a child process. The idea is to notify the parent each time an event occurs by sending it a signal, and letting the parent’s signal handler increment a global counter variable, which the parent can then inspect after the child has terminated. However, when he runs the test program in Figure 8.41 on his system, he discovers that when the parent calls printf, counter always has a value of 2, even though the child has sent ﬁve signals to the parent. Perplexed, he comes to you for help. Can you explain the bug?  

---  

### ***Answear***:  
The problem is that we are sending the signals ogether and the father is using a sleep so the signals are fused. if we put the sleep in the kill call instead of the handler the result will be different.  