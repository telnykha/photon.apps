	#define TURNON460 1                 
	#define TURNON660 2                 
	#define TURNON_CAM_660  3       	
	#define TURNON_CAM 4                
	#define TURN_OFF   5                
	#define TURNON_CAM_460   6          
	#define TURNON_CAM_460_ACT   7          
	#define TURNON460_ACT   8          
	#define TURNON_CAM_FLASH   9          
	const int progSize =18;
	expEvent Events[progSize] = {
{TURN_OFF,0,1000},
{TURNON_CAM,0,10},
{TURNON460,100,1000},
{TURNON_CAM_460,10,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON_CAM_460,20,60},
{TURNON460_ACT,10,2000},
{TURNON_CAM_460_ACT,10,60},
{TURNON_CAM_460_ACT,10,60},
{TURNON_CAM_460_ACT,10,60},
{TURN_OFF,0,100},
};
const int exposure = 300;
const int flash_delay = 75;
const int  flash_lenght = 84;
