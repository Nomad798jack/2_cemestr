import numpy as np
import matplotlib.pyplot as plt
from scipy.special import legendre
from matplotlib.animation import FuncAnimation
from matplotlib.widgets import Slider
from mpl_toolkits.mplot3d import Axes3D

def number1():
    x = np.linspace(-1, 1, 1000)
    colors = ['b', 'g', 'r', 'c', 'm', 'y', 'k']
    plt.figure(figsize=(10, 6))
    plt.title('Полиномы Лежандра')
    for n in range(1, 8):
        Pol = legendre(n)
        plt.plot(x, Pol(x), label=f'n = {n}', color=colors[n-1])

    plt.legend(loc='best')
    plt.grid(True)
    plt.show()

def number2():
    valueA = [3, 3, 5, 5]
    valueB = [2, 4, 4, 6]
    t = np.linspace(0, 2 * np.pi, 1000)
    fig, axs = plt.subplots(2, 2, figsize=(10, 10))
    for ax, a, b in zip(axs.flat, valueA, valueB):
        x = np.sin(a*t)
        y = np.sin(b*t)
        ax.plot(x, y)
        ax.set_title(f'Фигура Лизажу (a={a}, b={b})')
        ax.grid(True)
    plt.tight_layout()
    plt.show()

def number3():
    r = [3, 2]
    def update_Lissage(frame, line, t):
        line.set_data(np.sin(r[0]*T+frame), np.sin(r[1]*T+frame))
        return [line]   
    figure, axis = plt.subplots()
    T = np.linspace(0, 2*np.pi, 1000)
    X = np.sin(r[0] * T)
    Y = np.sin(r[1] * T)
    line, = axis.plot(X, Y)
    phase = np.linspace(0, 4*np.pi, 200)
    animation = FuncAnimation(
        figure, 
        func = update_Lissage,
        frames = phase, 
        fargs = (line, T),
        interval = 12,
        blit = True,
        repeat = True
    )
    plt.show()

def number4():
    fig, (first_ax, second_ax, sum_ax) = plt.subplots(3, 1, figsize=(20, 10))
    x = np.linspace(0, 5*np.pi, 500)
    A1, F1 = 1, 1
    A2, F2 = 1, 1
    wave1, = first_ax.plot(x, A1*np.sin(F1*x))
    wave2, = second_ax.plot(x, A2*np.sin(F2*x))
    wave_sum, = sum_ax.plot(x, A1*np.sin(F1*x)+A2*np.sin(F2*x))
    first_ax.set_title('Первая волна')
    second_ax.set_title('Вторая волна')
    sum_ax.set_title('Сочетание волн')
    axamp1 = plt.axes([0.1, 0.1, 0.3, 0.01])
    axfreq1 = plt.axes([0.1, 0.12, 0.3, 0.01])
    axamp2 = plt.axes([0.1, 0.14, 0.3, 0.01])
    axfreq2 = plt.axes([0.1, 0.16, 0.3, 0.01])
    a1_slide = Slider(axamp1, 'Амплитуда 1', 0.1, 2.0, valinit=A1)
    f1_slide = Slider(axfreq1, 'Частота 1', 0.1, 2.0, valinit=F1)
    a2_slide = Slider(axamp2, 'Амплитуда 2', 0.1, 2.0, valinit=A2)
    f2_slide = Slider(axfreq2, 'Частота 2', 0.1, 2.0, valinit=F2)
    def update(val):
        a1 = a1_slide.val
        f1 = f1_slide.val
        a2 = a2_slide.val
        f2 = f2_slide.val
        wave1.set_ydata(a1*np.sin(f1*x))
        wave2.set_ydata(a2*np.sin(f2*x))
        wave_sum.set_ydata(a1*np.sin(f1*x)+a2*np.sin(f2*x))
        fig.canvas.draw_idle()
    a1_slide.on_changed(update)
    f1_slide.on_changed(update)
    a2_slide.on_changed(update)
    f2_slide.on_changed(update)
    plt.show()

def number5():
    x = np.linspace(-1, 1, 100)
    y = np.linspace(-1, 1, 100)
    x, y = np.meshgrid(x, y)
    z = (x**2 + y**2)/2
    fig = plt.figure(figsize=(12, 6))
    ax1 = fig.add_subplot(121, projection='3d')
    ax1.plot_surface(x, y, z, cmap='viridis')
    ax1.set_title('MSE Surface')
    ax1.set_xlabel('X')
    ax1.set_ylabel('Y')
    ax1.set_zlabel('MSE')

    ax2 = fig.add_subplot(122, projection='3d')
    ax2.plot_surface(x, y, z, cmap='viridis')
    ax2.set_title('MSE Surface (Log Scale)')
    ax2.set_xlabel('X')
    ax2.set_ylabel('Y')
    ax2.set_zscale('log')
    ax2.set_zlabel('MSE (log scale)')
    plt.tight_layout()
    plt.show()