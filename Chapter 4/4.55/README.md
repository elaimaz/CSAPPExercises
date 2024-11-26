Exercise 4.55
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
The ﬁle pipe-btfnt.hcl contains a copy of the HCL code for PIPE, plus a declaration of the constant J_YES with value 0, the function code for an unconditional jump instruction. Modify the branch prediction logic so that it predicts conditional jumps as being taken when valC < valP (backward branch) and as being not-taken when valC ≥ val (forward branch). (Since Y86 does not support unsigned arithmetic, you should implement this test using a signed comparison.) Continue to predict unconditional jumps and call as being taken. You will need to devise a way to get both valC and valP to pipeline register M to recover from mispredicted branches. See the lab material for directions on how to generate a simulator for your solution and how to test it.

---  

### ***Answear***:  
[code](./pipe-btfnt.hcl).  

obs: used ChatGPT on this one!