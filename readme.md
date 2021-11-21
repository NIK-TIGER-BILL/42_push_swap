 # Push swap   
 --- 
 ### Description   
   
Ecole 42 common core project.   
It&#39;s about sorting numbers by using two stacks with set of rules. There are different commands:    
*ra rb rr* - rotation move first number to the end of stack (stack A, stack B, both)   
*sa sb ss* - swap first two numbers in stacks   
*rra rrb rrr* - reverse rotation the same as rotation but another way   
*pa pb* - push first number from stack to another   
   
Goals:   
- [x] **3** numbers should be sorted less than **3** steps    
- [x] **5** numbers should be sorted less than **12** steps   
- [x] **100** numbers should be sorted less than **700** steps   
- [x] **500** numbers should be sorted less than **5500** steps   
 ### How to execute   
1. spell **make**   
2. spell **./push\_swap 3 2 1 4 5** or **./push\_swap &#34;3 2 1 4 5&#34;**    
3. bash **bench.sh** to check algo 
4. ./push_swap $ARG | ./checker_Mac $ARG to check steps and final sorting.  
5. [visualizer](https://github.com/o-reo/push_swap_visualizer)    
   
   
![ALt_text](https://github.com/Gilliam6/Push_swap_with_chunks/blob/master/sorting.gif)   
