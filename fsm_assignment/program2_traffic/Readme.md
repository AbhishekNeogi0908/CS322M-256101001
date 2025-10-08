
---


```markdown
# Problem 2 – Two-Road Traffic Light (Moore)

## Aim
Design a Moore FSM to control **NS/EW traffic lights**.  
Timing sequence (1 Hz tick):  
- NS Green = 5 ticks  
- NS Yellow = 2 ticks  
- EW Green = 5 ticks  
- EW Yellow = 2 ticks  

Repeat indefinitely. Exactly one of {G, Y, R} is active per road.

- Type: **Moore**  
- Reset: **Synchronous, Active-High**  

---

## State Transition Explanation
- **S0 (00)**: NS Green, EW Red (5 ticks).  
- **S1 (01)**: NS Yellow, EW Red (2 ticks).  
- **S2 (10)**: EW Green, NS Red (5 ticks).  
- **S3 (11)**: EW Yellow, NS Red (2 ticks).  

FSM cycles **S0 → S1 → S2 → S3 → S0…** based on tick counter.  

---

## File Structure
problem2_traffic/
---traffic_light.v
---tb_traffic_light.v
---README.md
---waves/
    ---traffic_light.vcd
    ---1.png
    ---Traffic_Light_Moore.png


---

## Execution Pipeline
1. Reset → FSM starts in S0 (NS Green).  
2. Tick counter drives transitions from S0 to S1 to S2 to S3 and repeat accoding to appropreate input.  
3. Cycle repeats: 5/2/5/2 ticks.  
4. Verify correct durations in waveforms.  

---

## Simulation Commands
```bash $
iverilog -o simv traffic_light.v tb_traffic_light.v
vvp simv
gtkwave traffic_light.vcd

