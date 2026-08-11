Exercise 9.13
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Repeat Problem 9.11 for the following address:  

**Virtual address:** 0x0040  

1. Virtual address format  

| 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|    |    |    |    |   |   |   |   |   |   |   |   |   |   |  


2. Address translation  

| Parameter         | Value |
|:-----------------:|:-----:|
| VPN               |       |
| TLB index         |       |
| TLB tag           |       |
| TLB hit? (Y/N)    |       |
| Page fault? (Y/N) |       |
| PPN               |       |  


3. Physical address format  

| 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|    |    |   |   |   |   |   |   |   |   |   |   |  


4. Physical memory reference  

| Parameter           | Value |
|:-------------------:|:-----:|
| Byte offset         |       |
| Cache index         |       |
| Cache tag           |       |
| Cache hit? (Y/N)    |       |
| Cache byte returned |       |  

---  

### ***Answear***:  

1. Virtual address format  

| 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0  | 0  | 0  | 0  | 0 | 0 | 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |  


2. Address translation  

| Parameter         | Value |
|:-----------------:|:-----:|
| VPN               | 0x1   |
| TLB index         | 0x1   |
| TLB tag           | 0x0   |
| TLB hit? (Y/N)    | N     |
| Page fault? (Y/N) | Y     |
| PPN               | –     |  


3. Physical address format  

| 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| –  | –  | – | – | – | – | – | – | – | – | – | – |  


4. Physical memory reference  

| Parameter           | Value |
|:-------------------:|:-----:|
| Byte offset         | –     |
| Cache index         | –     |
| Cache tag           | –     |
| Cache hit? (Y/N)    | –     |
| Cache byte returned | –     |  