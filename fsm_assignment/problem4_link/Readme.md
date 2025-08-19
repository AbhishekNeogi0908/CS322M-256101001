
---

# Problem 4 – Master–Slave Handshake

```markdown
# Problem 4 – Master–Slave Handshake

## Aim
Design two FSMs (Master + Slave) for a **4-phase req/ack handshake** with an 8-bit data bus.  

Per byte:  
1. Master drives data, raises `req`.  
2. Slave latches data, asserts `ack` (2 cycles).  
3. Master sees `ack`, drops `req`.  
4. Slave drops `ack`.  

Master repeats for 4 bytes, then asserts `done`.  

- Type: **Two FSMs (Mealy-like)**  
- Reset: **Synchronous, Active-High**  

---

## State Transition Explanation
### Master FSM
- **S0 (Idle)**: Wait for start.  
- **S1 (Send)**: Drive data, raise req.  
- **S2 (Wait Ack)**: Hold until ack=1.  
- **S3 (Next/Done)**: Drop req, increment counter.  
- After 4 transfers → assert `done=1`.  

### Slave FSM
- **S0 (Wait)**: Wait for req=1.  
- **S1 (Latch)**: Capture data.  
- **S2 (Ack High)**: Assert ack for 2 cycles.  
- **S3 (Drop Ack)**: Return to idle.  

---

## File Structure
 problem4_link/
├── master_fsm.v
├── slave_fsm.v
├── link_top.v
├── tb_link_top.v
├── README.md
└── waves/
    ├── master_fsm.vcd
    ├── slave_fsm.vcd
    └── Link_Top.png
