    #define TURNON460 1                   
    #define TURNON660 2                   
    #define TURNON_CAM_660  3       
    #define TURNON_CAM 4                
    #define TURN_OFF   5                    
    #define TURNON_CAM_460   6                    
    const int progSize =11;
    expEvent Events[progSize] = {
{TURN_OFF,HIGH,1000},
{TURNON_CAM,HIGH,1000},
{TURNON460,HIGH,100},
{TURNON_CAM_660,HIGH,100},
{TURNON460,HIGH,10},
{TURNON_CAM,HIGH,1000},
{TURNON_CAM,HIGH,1000},
{TURNON_CAM,HIGH,1000},
{TURNON_CAM,HIGH,1000},
{TURNON_CAM_660,HIGH,1000},
{TURNON460,HIGH,5000},
};
