# Hardware Diagnostics Tool - C++/Qt Development Roadmap

## Project Goal

Build a native C++ diagnostics tool with a Walnut GUI that can detect and assess the status of hardware peripherals connected to a PC. The tool should provide simple, high-level feedback for issues with:

- Monitors (via EDID and DDC/CI)
- GPUs (driver status, basic sensors)
- CPUs (model, temperature, usage)
- USB devices (presence, speed, type)

## High-Level Features

### Phase 1: MVP (Minimum Viable Product)

- List connected monitors, GPUs, CPUs, and USB devices
- Perform basic communication checks (e.g., can DDC/CI be used with the monitor?)
- Basic health status summary for each device
- Clean GUI using framework built with Dear ImGui (StudioCherno/Walnut)
- Windows only in MVP stage

### Phase 2: Enhanced Diagnostics

- Temperature and usage sensors for CPU and GPU
- USB speed checks (2.0 vs 3.0)
- Driver status and version detection
- Detection of duplicate or ghost devices

### Phase 3: Export & Reporting

- Export diagnostics to JSON or plain text
- Generate a shareable summary report
- CLI version for headless/automated use

### Phase 4: Stress Tests and Advanced Modes

- Simple stress or loopback tests (for GPU, USB)
- Real-time sensor updates
- Live device monitoring tab

## Technology Stack

### Core Language

- C++17 or later
- Structured, modular code with CMake

### GUI Framework

- StudioCherno/Walnut
- Cross-platform native UI (Windows only for MVP)

### Hardware Access Libraries

| Device  | Platform       | APIs/Libraries                                             |
| ------- | -------------- | ---------------------------------------------------------- |
| Monitor | Windows/Linux  | EDID parsing, DDC/CI via I²C (Win32 API, i2c-dev on Linux) |
| GPU     | Windows        | NVIDIA NVAPI, AMD ADL SDK (C interface)                    |
| GPU     | Linux          | libdrm, sysfs (/sys/class/drm, /proc/...)                  |
| CPU     | Windows/Linux  | CPUID, MSRs, WMI (Win), `/proc`, `hwmon` (Linux)           |
| USB     | Cross-platform | libusb                                                     |

### Build System

- CMake (cross-platform project setup and IDE integration)

  _Build instructions will follow after MVP and V1 finished._

## Project Structure

```
/project-root
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── MainWindow.cpp / .h
│   ├── ui/ (Qt Designer .ui files)
│   ├── probes/
│   │   ├── MonitorProbe.cpp / .h
│   │   ├── GPUProbe.cpp / .h
│   │   ├── CPUProbe.cpp / .h
│   │   ├── USBProbe.cpp / .h
```

Each probe class will implement a consistent interface:

```cpp
struct DiagnosticResult {
    std::string deviceType;
    std::string name;
    bool healthy;
    std::string summary;
};
```

## Development Phases

### Phase 1 – Core CLI Logic (1–2 weeks)

- Build CLI-only version
- Implement Monitor EDID + basic DDC/CI test
- Enumerate GPUs and basic info (model/vendor)
- List USB devices with descriptors
- Output plain text summaries

### Phase 2 – Qt GUI Integration (1–2 weeks)

- Scaffold main window using Qt Designer
- Implement device list sidebar and detail view pane
- Integrate existing CLI probe logic into GUI backend

### Phase 3 – Diagnostic Engine and Health Checks (2 weeks)

- Implement status evaluation logic per device type
- Add smart summaries
- Enable refresh, rescanning, and error handling

### Phase 4 – Polishing, Packaging, and Deployment (2–3 weeks)

- Export results to file (JSON, plain text)
- Add settings dialog
- Create Windows installer
- Create Linux AppImage or DEB package

## Optional Enhancements

- Real-time performance graphs (Qt charts or QCustomPlot)
- Remote diagnostics (future plugin or web API)
- System tray integration
- Command-line mode for sysadmins

## Tools and Setup

- IDE: Qt Creator or CLion (optional: Visual Studio with CMake integration)
- Version control: Git
- Debugging: Qt's built-in debugger, GDB, or Visual Studio
- Dependencies: Qt6, libusb, vendor SDKs, optional: open hardware sensor libs

## Key Design Principles

- **Modular**: Probes are self-contained and extendable
- **Cross-platform**: Windows and Linux first, macOS optionally
- **Minimal Permissions**: Avoid requiring admin unless strictly necessary
- **Readable Summaries**: Designed for users with basic understanding of hardware

---
