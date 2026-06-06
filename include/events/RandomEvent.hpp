//
// Created by bartl on 31.05.2026.
//


#ifndef SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
#define SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP

#include <core/Army.hpp>

/**
 * @brief Interface for random events that can affect an army during battle.
 */
class RandomEvent
{
public:
    /// Allows deleting derived event objects through a base pointer.
    virtual ~RandomEvent() = default;

    /**
     * @brief Applies the event effect to the selected army.
     * @param army Army affected by the event.
     */
    virtual void apply(Army& army) = 0;
    /**
     * @brief Returns event name displayed in the current-event label.
     */
    virtual std::string getName() const = 0;
};

#endif //SIMULATION_BATTLE_OF_GRUNWALD_RANDOMEVENT_HPP
