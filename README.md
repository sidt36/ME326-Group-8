# ME326-Group-8

## Installation Notes

### April Tag Models
You need to copy the April Tag models to the `.gazebo/model` directory, or add the full path to `gazebo_aptriltag/models` to the `GAZEBO_MODEL_PATH` environment variable.

To copy the models, run the following commands:
```bash
cp -r gazebo_apriltag/models/* ~/.gazebo/models/
```

If the `~/.gazebo/models` directory does not exist, you can create it by running the following command:
```bash
mkdir -p ~/.gazebo/models
```