
---

# Problem 3 – Vending Machine (Mealy)

```markdown
# Problem 3 – Vending Machine with Change (Mealy)

## Aim
Design a vending machine FSM.  

- Price = 20  
- Accepts coins: `5` or `10` (`coin[1:0]`: 01=5, 10=10, 00=idle)  
- On total ≥ 20: assert `dispense=1` for 1 cycle.  
- If total=25: assert `chg5=1` for 1 cycle (return change).  
- Reset total after vending.  

- Type: **Mealy**  
- Reset: **Synchronous, Active-High**  

---

##  State Transition Explanation
- **S0 (00)**: Total = 0  
- **S5 (01)**: Total = 5  
- **S10 (10)**: Total = 10  
- **S15 (11)**: Total = 15  


- Output is produced if from S15:  
  - Coin=5 → Total=20 → `dispense=1`, reset to S0  
  - Coin=10 → Total=25 → `dispense=1`, `chg5=1`, reset to S0  

---

## File Structure

problem3_vending/
--- vending_mealy.v
--- tb_vending_mealy.v
--- README.md
--- waves/
    --- vending_mealy.vcd
    --- 3.png
    --- Vending_Mealy.png


---

## Execution Pipeline
1. Reset → FSM enters S0.  
2. Insert coins step by step.  
3. FSM asserts outputs when target reached.  
4. Resets to S0 after vending.  

---

##  Simulation Commands
```bash $
iverilog -o sim_out tb_vending_mealy.v
vvp sim_out
gtkwave vending_mealy.vcd
```

