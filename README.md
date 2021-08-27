# decoy
a data structure type
```
                                        ██▓▓▓▓                                          
                                    ████      ████                                      
                                ▒▒▒▒▒▒░░      ░░░░▒▒▒▒                                  
                            ▓▓▓▓░░░░              ░░▒▒▓▓██                              
                        ████                            ▒▒██                            
                    ████                            ▒▒▒▒    ██                          
                ████                            ▒▒▒▒          ██                        
            ████                            ▒▒▒▒  ████          ██                      
        ▓▓▓▓                            ░░░░  ██▓▓▓▓▓▓██        ██                      
      ██                            ▒▒▒▒░░████▓▓▓▓▓▓▓▓██    ▓▓  ██                      
    ██  ▒▒▒▒                    ▒▒▒▒  ████▓▓▓▓▓▓▓▓▓▓▓▓██  ████  ██                      
    ██      ░░░░            ░░░░  ████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██  ██░░  ██                      
    ██          ▒▒▒▒    ▒▒▒▒  ████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██    ▒▒  ██                      
    ██              ▒▒▒▒  ████▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██  ▒▒    ██                      
    ██                ░░██▓▓▓▓▓▓▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██    ██  ██                      
    ██                ░░██▓▓░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██  ████  ██                      
    ██                ░░██▓▓▓▓░░▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██  ████  ██                      
    ██                ░░██▓▓▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██  ██    ██                      
    ██                ░░██▓▓░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██        ██                      
    ██                ░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓██        ██                      
    ██                ░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████      ████                        
    ██                ░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████      ████▒▒██                        
    ██                ░░██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓████      ████▒▒▒▒▒▒██████                    
    ██                ░░██▓▓▓▓▓▓▓▓▓▓▓▓████      ████▒▒▒▒▒▒████      ██                  
    ██                ░░██▓▓▓▓▓▓▓▓████      ████▒▒▒▒▒▒████      ██████                  
    ████              ░░██▓▓▓▓████      ████▒▒▒▒▒▒████      ████      ██                
      ██▓▓▓▓          ░░  ████      ▓▓▓▓▒▒▒▒▒▒████░░    ██▓▓    ▓▓██    ██              
    ██▒▒▒▒▒▒▓▓▓▓      ░░        ██▓▓▒▒▒▒▒▒████      ▓▓██░░░░▓▓▓▓░░░░██  ░░██            
    ██████▒▒▒▒▒▒████  ░░    ████▒▒▒▒▒▒████      ████    ████      ▒▒  ██    ██          
    ██    ████▒▒▒▒▒▒████████▒▒▒▒▒▒████      ████    ████      ░░    ▒▒  ██    ██        
    ██        ████▒▒▒▒▒▒▒▒▒▒▒▒████      ████    ████      ░░    ░░    ░░  ██    ██      
    ██            ████████████      ████    ████      ░░    ░░    ▒▒    ░░  ██    ██    
  ██                            ████    ████      ▒▒    ▒▒    ░░    ▒▒        ██    ██  
  ██                        ████    ████      ░░    ░░    ░░    ░░        ████    ██████
  ██                      ██  ██    ██    ░░    ░░    ░░    ░░        ▓▓██    ▓▓▓▓    ██
  ████                  ██      ██    ██    ░░    ░░    ░░        ████  ░░▓▓▓▓        ██
      ████              ██        ██    ██    ░░    ░░        ████    ████            ██
          ████          ██          ██    ██    ░░        ████    ████            ████  
          ░░░░▒▒▒▒      ██            ▒▒  ▒▒▒▒  ░░    ▒▒▒▒░░░░▒▒▒▒▒▒          ▒▒▒▒      
                  ████  ██              ██  ░░▓▓  ████░░  ▓▓▓▓░░░░        ████          
                      ████                ██    ██    ████            ████              
                          ████              ██    ████            ████                  
                              ████            ████            ████                      
                                  ▓▓▓▓                    ▓▓▓▓                          
                                      ▓▓▓▓            ▓▓▓▓                              
                                      ░░░░▓▓▓▓    ████░░░░                              
                                          ░░░░▓▓▓▓░░                                    

```                                                        
