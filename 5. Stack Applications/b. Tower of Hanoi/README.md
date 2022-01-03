## Tower of Hanoi Logic

__Take an example for 2 disks :__
    ___Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.___

- __Step 1 : Shift first disk from 'A' to 'B'.__
- __Step 2 : Shift second disk from 'A' to 'C'.__
- __Step 3 : Shift first disk from 'B' to 'C'.__

__The pattern here is :__
- Shift 'n-1' disks from 'A' to 'B'.
- Shift last disk from 'A' to 'C'.
- Shift 'n-1' disks from 'B' to 'C'.

__Program Output Examples__
- ___Input : 2___
    - __Output : Disk 1 moved from A to B__
        - __Disk 2 moved from A to C__
        - __Disk 1 moved from B to C__

- ___Input : 3___
    - __Output : Disk 1 moved from A to C__
        - __Disk 2 moved from A to B__
        - __Disk 1 moved from C to B__
        - __Disk 3 moved from A to C__
        - __Disk 1 moved from B to A__
        - __Disk 2 moved from B to C__
        - __Disk 1 moved from A to C__

