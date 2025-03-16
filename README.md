# @HACK 2025: Stack Smashing

> Authored by [Anis](https://github.com/AnixPasBesoin).

- **Category**: `Pwn`
- **Value**: `200 points`
- **Tags**: `beginner` `tcp`

> After connecting to the TCP server given bellow, a confusing question will await you. Answer it "correctly", 
> and you'll be rewarded with the flag. Btw, "correctly" is not the answer.
> 
> An identical copy of the binary that guards the flag is at your disposal - you will need to dive into it.
> 

## Files
- **[Download: server](https://github.com/athack-ctf/chall2025-stack-smashing/raw/refs/heads/main/offline-artifacts/server)**

## Access a dockerized instance

Run challenge container using docker compose
```
docker compose up -d
```
Connect to the TCP socket (e.g., using nc command)
```
nc localhost 52030 
```
<details>
<summary>
How to stop/restart challenge?
</summary>

To stop the challenge run
```
docker compose stop
```
To restart the challenge run
```
docker compose restart
```

</details>


## Reveal Flag

Did you try solving this challenge?
<details>
<summary>
Yes
</summary>

Did you **REALLY** try solving this challenge?

<details>
<summary>
Yes, I promise!
</summary>

Flag: `ATHACKCTF{0xdeadbeef_5t4ck_8453d_8uff3r_0v3rf10w}`

</details>
</details>


---

## About @HACK
[@HACK](https://athackctf.com/) is an annual CTF (Capture The Flag) competition hosted by [HEXPLOIT ALLIANCE](https://hexploit-alliance.com/) and [TECHNATION](https://technationcanada.ca/) at Concordia University in Montreal, Canada.

---
[Check more challenges from @HACK 2025](https://github.com/athack-ctf/AtHackCTF-2025-Challenges).