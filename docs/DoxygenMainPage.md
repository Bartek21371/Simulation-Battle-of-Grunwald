# Simulation Battle of Grunwald

This documentation is generated with Doxygen from comments in the C++ source
code.

## Main Modules

- `core` - battle flow, armies and battle statistics.
- `warriors` - warrior hierarchy used during combat.
- `events` - random battle events and weather.
- `config` - CSV configuration loading.
- `gui` - Qt widgets used to run and display the simulation.
- `reports` - CSV battle report generation.

## Generate Documentation

Run this command from the repository root:

```bash
doxygen Doxyfile
```

Generated HTML documentation is written to:

```text
docs/doxygen/html/index.html
```

## UML Diagrams

Additional UML diagrams are stored in `docs/UML`.
