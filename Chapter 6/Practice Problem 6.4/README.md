### ***Practice Problem 6.4***:  
Estimate the average time (in ms) to access a sector on the following disk:  


| Parameter  | Value |
| ------------- | ------------- |
| Rotational rate  | 10000 RPM |
| T<sub>avg seek</sub> | 5 ms |
| Average # sectors/track | 1000 |
| Surfaces | 4 |
| Sector size | 512 bytes |  

&emsp;For each case below, suppose that a program reads the logical blocks of the ﬁle sequentially, one after the other, and that the time to position the head over the ﬁrst block is T<sub>avg seek</sub> + T<sub>avg rotation</sub>.  

1. Best case: Estimate the optimal time (in ms) required to read the ﬁle given the best possible mapping of logical blocks to disk sectors (i.e., sequential).  
2. Random case: Estimate the time (in ms) required to read the ﬁle if blocks are mapped randomly to disk sectors.

---  

### ***Answear***:  
1.

$$ T_\text{avg rotation} = \frac{1}{2} * T_\text{max rotation} $$  

$$ T_\text{avg rotation} = \frac{1}{2} * \frac{1}{\text{RPM}} * \frac{1}{\text{Average \texttt{\#} sectors/track}} * \frac{60 \text{ secs}}{1 \text{ min}} $$

$$ T_\text{avg rotation} = \frac{1}{2} * \frac{1}{10000} * \frac{60 \text{ secs}}{1 \text{ min}} $$

$$ T_\text{avg rotation} =  0.003\text{ s} $$

$$ T_\text{avg rotation} =  3\text{ ms} $$  

---  

$$ T_\text{max rotation} =  \frac{1}{10000\text{ RPM}} * \frac{60 \text{ secs}}{1 \text{ min}} $$  

$$ T_\text{max rotation} =  0.006\text{ secs} $$  

$$ T_\text{max rotation} =  6\text{ ms} $$

---  

$$ T_\text{avg seek} + T_\text{avg rotation} + 2 * T_\text{max rotation} $$  

$$ 5\text{ ms} + 3\text{ ms} + 2 * 6\text{ ms} $$  

$$ 5\text{ ms} + 3\text{ ms} + 2 * 6\text{ ms} $$  

$$ 20\text{ ms} $$  

---  

2. 

$$ (T_\text{avg seek} + T_\text{avg rotation}) * 2000 $$  

$$ (5\text{ ms} + 3\text{ ms}) * 2000 $$  

$$ 16000\text{ ms} $$  

$$ 16\text{ secs} $$
