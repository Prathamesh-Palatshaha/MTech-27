import matplotlib.pyplot as plt
import matplotlib.patches as patches
import os
import time

# -------------------------------
# Create folder for snapshots
# -------------------------------
SNAPSHOT_DIR = "snapshots"
os.makedirs(SNAPSHOT_DIR, exist_ok=True)

# -------------------------------
# Define the 2x2 environment
# -------------------------------
environment = {
    "Room1": "Clean",
    "Room2": "Dirty",   # Start with dirt here
    "Room3": "Clean",
    "Room4": "Clean"
}

room_positions = {
    "Room1": (0, 1),
    "Room2": (1, 1),
    "Room3": (0, 0),
    "Room4": (1, 0)
}

rooms = list(environment.keys())
agent_index = 0

# -------------------------------
# Reflex Agent
# -------------------------------
def reflex_agent(state):
    if state == "Dirty":
        return "Clean"
    return "Move"

# -------------------------------
# Draw Environment (Enhanced UI)
# -------------------------------
def draw_environment(env, agent_pos, step, action):
    fig, ax = plt.subplots(figsize=(6, 6))
    ax.set_xlim(0, 2)
    ax.set_ylim(0, 2)
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_title(f"Vacuum Cleaner Agent — Step {step}", fontsize=14, weight="bold")

    # Draw rooms
    for room, (x, y) in room_positions.items():
        is_dirty = env[room] == "Dirty"
        color = "#D98880" if is_dirty else "#82E0AA"

        rect = patches.Rectangle(
            (x, y), 1, 1,
            facecolor=color,
            edgecolor="black",
            linewidth=2
        )
        ax.add_patch(rect)

        status_icon = "🟤 Dirty" if is_dirty else "🟢 Clean"
        ax.text(
            x + 0.5, y + 0.6,
            room,
            ha="center", va="center",
            fontsize=11, weight="bold"
        )
        ax.text(
            x + 0.5, y + 0.4,
            status_icon,
            ha="center", va="center",
            fontsize=10
        )

    # Draw agent
    agent_x, agent_y = room_positions[rooms[agent_pos]]
    agent = patches.Circle(
        (agent_x + 0.5, agent_y + 0.5),
        0.15,
        facecolor="#3498DB",
        edgecolor="white",
        linewidth=2
    )
    ax.add_patch(agent)

    # Info box
    info_text = (
        f"Agent Location: {rooms[agent_pos]}\n"
        f"Action Taken: {action}"
    )
    ax.text(
        0.02, -0.25,
        info_text,
        transform=ax.transAxes,
        fontsize=10,
        bbox=dict(boxstyle="round", facecolor="#F4F6F7")
    )

    # Save snapshot
    filename = f"{SNAPSHOT_DIR}/step_{step}.png"
    plt.savefig(filename, bbox_inches="tight")
    plt.pause(0.8)
    plt.close()

# -------------------------------
# Run Simulation
# -------------------------------
plt.ion()
steps = 8

for step in range(steps):
    current_room = rooms[agent_index]
    state = environment[current_room]
    action = reflex_agent(state)

    draw_environment(environment, agent_index, step + 1, action)

    if action == "Clean":
        environment[current_room] = "Clean"
    else:
        agent_index = (agent_index + 1) % len(rooms)

plt.ioff()
print("✅ Simulation complete!")
print(f"📸 Snapshots saved in '{SNAPSHOT_DIR}' folder")
