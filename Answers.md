1. Not sure, to be honest. I joined in after the Processes lesson. My guess would be B.


2. Taking a guess here:
  Start — Initial state when a process is first started.
  Ready — Process is waiting to be assigned to a processor.
  Running — After the OS scheduler assigns a process to a processor, the processor excutes its instructions.
  Waiting — Process is in waiting state if it needs to wait for a resource or user input.
  Terminated/Exit — Process finishes its execution, or is terminated by the OS.


3. On my computer, a printf call averages to 592 ns, whereas a write call averages to 3699 ns.


4. The reason printf is faster than write is because printf buffers its output in memory and only calls write when its buffer is full.