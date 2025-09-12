### ***Practice Problem 6.3***:  
Estimate the average time (in ms) to access a sector on the following disk:  


| Parameter  | Value |
| ------------- | ------------- |
| Rotational rate  | 15000 RPM  |
| T<sub>avg seek</sub> | 8 ms  |
| Average # sectors/track | 500  |

---  

### ***Answear***:  

$$ T_{\text{avg rotation}} = \frac{1}{2} * T_{\text{max rotation}} $$  

$$ T_{\text{avg rotation}} = \frac{1}{2} * (\frac{60 \text{ secs}}{15000 \text{ RPM}}) * 1000 \text{ ms/sec} $$  

$$ T_{\text{avg rotation}} = 2 \text{ ms} $$  

---  

$$ T_{\text{avg transfer}} = \frac{60}{15000 \text{ RPM}} * \frac{1}{500 \text{ sectors/track}} * 1000 \text{ ms/sec} $$  

$$ T_{\text{avg transfer}} =  0.008 \text{ ms} $$  

---  

$$ T_{\text{access}} = T_{\text{avg seek}} + T_{\text{avg rotation}} + T_{\text{avg transfer}} $$  

$$ T_{\text{access}} = 8 \text{ ms} + 2 \text{ ms} + 0.008 \text{ ms} $$  

$$ T_{\text{access}} = 10.008 \text{ ms} $$  


