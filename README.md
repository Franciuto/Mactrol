# Mactrol

### Overview
This project showcases a highly customizable 3D-printed 3x3 macropad powered by a Raspberry Pi Zero as the host device. Designed for flexibility, the macropad features 9 blue mechanical switches arranged in a 3x3 matrix configuration, combined with rotary encoders for additional functionality. It runs on a custom version of QMK Firmware tailored for specific needs but remains fully adaptable for different user requirements.

## Features
- **Host Device**: Raspberry Pi Zero
- **Switches**: 9 blue mechanical switches in a 3x3 matrix layout
- **Firmware**: Customized QMK Firmware for enhanced configurability
- **Encoders**: Integrated rotary encoders for extra input options
- **Customizability**: Open to user modifications for diverse applications

## Requirements
### Hardware
- Raspberry Pi Zero (or compatible host device)
- 9 blue mechanical switches
- Rotary encoders
- 3D-printed case (files included in this repository)

### Software
- QMK Firmware (customized version available in this repository)
- Required libraries and dependencies for QMK setup

## Setup
1. **Assemble the Hardware**:
   - Install the switches and wire them
   - Connect the rotary encoders to the board.
   - Mount the components in the 3D-printed case.

2. **Flash the Firmware**:
   - Clone the QMK Firmware repository.
   - Navigate to the custom firmware directory provided in this project.
   - Compile and flash the firmware to the Raspberry Pi Zero.

4. **Customize the Configuration**:
   - Edit the keymaps.c file as you like
   - Recompile and upload the updated firmware.

## Usage
Once set up, the macropad functions as a plug-and-play device. It can be configured for:
- Productivity shortcuts
- Gaming macros
- Media controls
- Any other application requiring custom input

## Customization
This macropad is designed for full user customization:
- Modify the QMK keymaps and firmware to add new layers, macros, or behaviors.
- Adapt the 3D-printed case design to fit specific preferences or additional components.
- Adjust the matrix configuration to support different switch types or layouts.

## 3D Printing
The repository includes STL files for the 3D-printed case. Ensure that the files are compatible with your 3D printer. Suggested print settings:

## License
This project is open-source and distributed under the MIT License. Feel free to fork, modify, and share your improvements.
