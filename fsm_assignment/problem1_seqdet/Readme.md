# Problem 1 – Overlapping Sequence Detector (Mealy)

## Aim
Design a Mealy FSM to detect the **serial bit pattern `1101`** on input `din`.  
When the last bit of the pattern arrives, output `y` must pulse high for **1 clock cycle**.  
Overlapping sequences must also be detected.  

- Type: Mealy Machine  
- Reset: Synchronous, Active-High  

---

## State Transition Explanation
- **S0 (00)** : Idle / no match yet.  
- **S1 (01)** : Last bit was `1`.  
- **S2 (10)** : Last two bits were `11`.  
- **S3 (11)** : Last three bits were `110`.  

If next input is `1` at S3 → sequence `1101` detected → output `y=1` for 1 cycle.  
FSM then falls back to **S1** for overlap handling.  

---

## Execution Pipeline
1. Reset → FSM starts in S0.  
2. Feed input stream (e.g., 11011011101).  
3. FSM asserts `y=1` whenever `1101` detected.  
4. Supports overlapping detection.  

---

## File structure 

problem1_seqdet/
--- seq_detect_mealy.v
--- tb_seq_detect_mealy.v
--- Readme.md
--- waves/
    --- seq_detect_mealy.vcd
    --- 1.png
    --- Seq_detect_Mealy.png

## Simulation Commands
```bash : $
iverilog -o simv seq_detect_mealy.v tb_seq_detect_mealy.v
vvp simv
gtkwave seq_detect_vcd_file.vcd

