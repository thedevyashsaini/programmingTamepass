# import pygame
# import random

# # Initialize Pygame
# pygame.init()

# # Constants
# WIDTH, HEIGHT = 640, 480
# GRID_SIZE = 20
# GRID_WIDTH = WIDTH // GRID_SIZE
# GRID_HEIGHT = HEIGHT // GRID_SIZE
# FPS = 10
# BLACK = (0, 0, 0)
# GREEN = (0, 255, 0)
# RED = (255, 0, 0)

# # Create the screen
# screen = pygame.display.set_mode((WIDTH, HEIGHT))
# pygame.display.set_caption("Snake Game")

# # Snake class
# class Snake:
#     def _init_(self):
#         self.body = [(GRID_WIDTH // 2, GRID_HEIGHT // 2)]
#         self.direction = random.choice(["UP", "DOWN", "LEFT", "RIGHT"])

#     def move(self):
#         x, y = self.body[0]
#         if self.direction == "UP":
#             y -= 1
#         elif self.direction == "DOWN":
#             y += 1
#         elif self.direction == "LEFT":
#             x -= 1
#         elif self.direction == "RIGHT":
#             x += 1
#         self.body.insert(0, (x, y))
#         self.body.pop()

#     def change_direction(self, new_direction):
#         if new_direction == "UP" and self.direction != "DOWN":
#             self.direction = new_direction
#         elif new_direction == "DOWN" and self.direction != "UP":
#             self.direction = new_direction
#         elif new_direction == "LEFT" and self.direction != "RIGHT":
#             self.direction = new_direction
#         elif new_direction == "RIGHT" and self.direction != "LEFT":
#             self.direction = new_direction

#     def grow(self):
#         x, y = self.body[0]
#         if self.direction == "UP":
#             y -= 1
#         elif self.direction == "DOWN":
#             y += 1
#         elif self.direction == "LEFT":
#             x -= 1
#         elif self.direction == "RIGHT":
#             x += 1
#         self.body.insert(0, (x, y))

#     def draw(self):
#         for x, y in self.body:
#             pygame.draw.rect(screen, GREEN, (x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE, GRID_SIZE))

# # Food class
# class Food:
#     def _init_(self):
#         self.x = random.randint(0, GRID_WIDTH - 1)
#         self.y = random.randint(0, GRID_HEIGHT - 1)

#     def draw(self):
#         pygame.draw.rect(screen, RED, (self.x * GRID_SIZE, self.y * GRID_SIZE, GRID_SIZE, GRID_SIZE))

# # Create the snake and food
# snake = Snake()
# food = Food()

# # Create a clock object to control the frame rate
# clock = pygame.time.Clock()

# # Main game loop
# while True:
#     for event in pygame.event.get():
#         if event.type == pygame.QUIT:
#             pygame.quit()
#             sys.exit()
#         elif event.type == pygame.KEYDOWN:
#             if event.key == pygame.K_UP:
#                 snake.change_direction("UP")
#             elif event.key == pygame.K_DOWN:
#                 snake.change_direction("DOWN")
#             elif event.key == pygame.K_LEFT:
#                 snake.change_direction("LEFT")
#             elif event.key == pygame.K_RIGHT:
#                 snake.change_direction("RIGHT")

#     # Move the snake
#     snake.move()

#     # Check for collision with food
#     if snake.body[0] == (food.x, food.y):
#         snake.grow()
#         food = Food()

#     # Check for collision with walls or self
#     if (
#         snake.body[0][0] < 0 or
#         snake.body[0][0] >= GRID_WIDTH or
#         snake.body[0][1] < 0 or
#         snake.body[0][1] >= GRID_HEIGHT or
#         snake.body[0] in snake.body[1:]
#     ):
#         pygame.quit()
#         sys.exit()

#     # Draw everything
#     screen.fill(BLACK)
#     snake.draw()
#     food.draw()

#     # Update the display
#     pygame.display.flip()

#     # Cap the frame rate
#     clock.tick(FPS)


# import matplotlib.pyplot as plt

# # Sample data
# x = [1, 2, 3, 4, 5]
# y = [2, 1, 6, 2, 15]

# # Create a basic line plot
# plt.plot(x, y)

# # Add labels and title
# plt.xlabel('X-axis')
# plt.ylabel('Y-axis')
# plt.title('Simple Line Plot')

# # Show the plot
# plt.show()


# string =input("give an input sentence:") 
# splits = [] 
# pos = -1 
# last_pos = -1  

# while ' ' in string[pos + 1:]: 
#    pos = string.index(' ', pos + 1) 
# splits.append(string[last_pos + 1:pos]) 
# last_pos = pos 
# splits.append(string[last_pos + 1:])
# print(splits)

# cook your dish here


for _ in range(int(input().strip())):
    n = int(input().strip())
    s = input().strip()
    ml = {}
    count = 1
    for i in s:
        if i not in ml:
            c = s.count(i)
            # count *= c
            ml[i] = c
    print(ml)
    ml = sorted(ml.items(), key=lambda x: x[1], reverse=True)
    for i in range(1, n+1):
        
        
    # print(count % ((10 ** 9) + 7))