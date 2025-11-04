Exercise 6.36
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Repeat Problem [6.35](../6.35/README.md) for a cache with a total size of 128 data bytes.  

| **dst array** |           |           |           |           |   | **src array** |           |           |           |           |
| :------------ | :-------: | :-------: | :-------: | :-------: |---| :------------ | :-------: | :-------: | :-------: | :-------: |
| **Row 0**     |           |           |           |           |   | **Row 0**     |           |           |           |           |
| **Row 1**     |           |           |           |           |   | **Row 1**     |           |           |           |           |
| **Row 2**     |           |           |           |           |   | **Row 2**     |           |           |           |           |
| **Row 3**     |           |           |           |           |   | **Row 3**     |           |           |           |           |
|               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |   |               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |


---  

### ***Answear***:  

| **dst array** |           |           |           |           |   | **src array** |           |           |           |           |
| :------------ | :-------: | :-------: | :-------: | :-------: |---| :------------ | :-------: | :-------: | :-------: | :-------: |
| **Row 0**     |     m     |     h     |     h     |     h     |   | **Row 0**     |     m     |    h      |    h      |     h     |
| **Row 1**     |     m     |     h     |     h     |     h     |   | **Row 1**     |     m     |    h      |    h      |     h     |
| **Row 2**     |     m     |     h     |     h     |     h     |   | **Row 2**     |     m     |    h      |    h      |     h     |
| **Row 3**     |     m     |     h     |     h     |     h     |   | **Row 3**     |     m     |    h      |    h      |     h     |
|               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |   |               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |


### ***Notes***: :memo:  

Remember that the cache has 8 blocks (128 / 16), since we have 8 blocks each line in src and dst array will have it's own line on cache.  