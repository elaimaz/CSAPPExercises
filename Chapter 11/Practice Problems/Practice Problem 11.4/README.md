### ***Practice Problem 11.4***:  
Compile the hostinfo program from Figure 11.12. Then run hostinfo google.com three times in a row on your system.  

1. What do you notice about the ordering of the IP addresses in the three host entries?  
2. How might this ordering be useful?  

---  

### ***Answear***:  
1. The address was the same 3 times.  
2. The different ordering of the addresses in different DNS queries is known as DNS round-robin. It can be used to load-balance requests to a heavily used domain name.  
