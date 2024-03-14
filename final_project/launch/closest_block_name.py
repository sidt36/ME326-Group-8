import yaml

def parse_cube_data(file_path):
    with open(file_path, 'r') as file:
        cubes = yaml.safe_load(file)
    return cubes
def return_name(x_d, y_d, z_d, required_color = 'blue' ):
    file_path = 'cube_name_location.yaml'
    cubes = parse_cube_data(file_path)
    # x_d = 0.85
    # y_d = 1
    # z_d = 2
    MIN = 1000000
    MIN_INSTANCE = ""
    X_INSTANCE = 0
    Y_INSTANCE = 0
    Z_INSTANCE = 0
    key_instance = ""
    for key in cubes.keys(): 
        x = cubes[key]['arguments']['x']
        y = cubes[key]['arguments']['y']
        z = cubes[key]['arguments']['z']
        if(cubes[key]['color'] == required_color):
            if((x - x_d)**2 + (y-y_d)**2 + (z - z_d)**2<MIN):
                MIN = (x - x_d)**2 + (y-y_d)**2 + (z - z_d)**2
                MIN_INSTANCE = cubes[key]['arguments']['entity']
                print(MIN_INSTANCE)
                X_INSTANCE = x
                Y_INSTANCE = y
                Z_INSTANCE = z
                key_instance = key

    cubes[key_instance]['Enabled'] = 0 

    return [X_INSTANCE,Y_INSTANCE,Z_INSTANCE], MIN_INSTANCE


print(return_name(1,1,1))
# Clean Up 
# for key in cubes.keys():
#     curr_instance = cubes[key]
#     cubes[key]['Enabled'] = 1