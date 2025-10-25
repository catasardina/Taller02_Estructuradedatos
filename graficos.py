import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
from matplotlib.ticker import FormatStrFormatter

def grafico_rendimiento_operaciones(df,maquina):
    # Crear la figura
    plt.figure(figsize=(12, 7))

    # Graficar cada operación con diferente color (sin marcadores)
    sns.lineplot(data=df, x='Tamaño', y='Insercion', 
                linewidth=2.5, label='Inserción', color='#2ecc71')

    sns.lineplot(data=df, x='Tamaño', y='Busqueda', 
                linewidth=2.5, label='Búsqueda', color='#3498db')

    sns.lineplot(data=df, x='Tamaño', y='Multiplicacion', 
                linewidth=2.5, label='Multiplicación', color='#e74c3c')

    # Personalizar el gráfico
    plt.xlabel('Número de Elementos', fontsize=14, fontweight='bold')
    plt.ylabel('Tiempo Promedio (segundos)', fontsize=14, fontweight='bold')
    plt.title(f'Análisis de Rendimiento en Maquina {maquina}', 
            fontsize=16, fontweight='bold', pad=20)

    # Formatear el eje Y para mostrar 4 decimales
    ax = plt.gca()
    ax.yaxis.set_major_formatter(FormatStrFormatter('%.4f'))

    # Mejorar la leyenda
    plt.legend(title='Operación', title_fontsize=12, fontsize=11, 
            loc='upper left', frameon=True, shadow=True)

    # Añadir grid más sutil
    plt.grid(True, alpha=0.3, linestyle='--')

    # Ajustar layout y guardar
    plt.tight_layout()
    nombre = f'rendimiento de operaciones en {maquina}.png'
    plt.savefig(f'images/{nombre}', dpi=300, bbox_inches='tight')
    print(f"✓ Gráfica guardada como '{nombre}'")

    # Mostrar gráfica
    plt.show()

    # Imprimir tabla de resultados
    print("\n" + "="*60)
    print("RESUMEN DE RESULTADOS")
    print("="*60)
    print(df.to_string(index=False))
    print("="*60)

def comparativa_maquinas_multiplicacion(df_intel,df_AMD):
    # Crear la figura
    plt.figure(figsize=(12, 7))

    # Graficar multiplicación de ambas máquinas
    sns.lineplot(data=df_intel, x='Tamaño', y='Multiplicacion', 
                linewidth=2.5, label='Intel Core i5', color='#3498db')

    sns.lineplot(data=df_AMD, x='Tamaño', y='Multiplicacion', 
                linewidth=2.5, label='AMD Ryzen', color='#e74c3c')

    # Personalizar el gráfico
    plt.xlabel('Número de Elementos', fontsize=14, fontweight='bold')
    plt.ylabel('Tiempo Promedio (segundos)', fontsize=14, fontweight='bold')
    plt.title('Comparativa de Tiempos de Multiplicación - Intel vs AMD', 
            fontsize=16, fontweight='bold', pad=20)

    # Formatear el eje Y para mostrar 4 decimales
    ax = plt.gca()
    ax.yaxis.set_major_formatter(FormatStrFormatter('%.4f'))

    # Mejorar la leyenda
    plt.legend(title='Procesador', title_fontsize=12, fontsize=11, 
            loc='upper left', frameon=True, shadow=True)

    # Añadir grid más sutil
    plt.grid(True, alpha=0.3, linestyle='--')

    # Ajustar layout y guardar
    plt.tight_layout()
    plt.savefig('images/comparativa_multiplicacion_intel_vs_amd.png', dpi=300, bbox_inches='tight')
    print("✓ Gráfica comparativa guardada como 'comparativa_multiplicacion_intel_vs_amd.png'")

    # Mostrar gráfica
    plt.show()

    # Imprimir tabla comparativa
    print("\n" + "="*70)
    print("TABLA COMPARATIVA - MULTIPLICACIÓN")
    print("="*70)
    print(f"{'Tamaño':<15} {'Intel (s)':<20} {'AMD (s)':<20} {'Diferencia':<15}")
    print("-"*70)
    
    for i in range(len(df_intel)):
        tamano = df_intel.iloc[i]['Tamaño']
        tiempo_intel = df_intel.iloc[i]['Multiplicacion']
        tiempo_amd = df_AMD.iloc[i]['Multiplicacion']
        diferencia = abs(tiempo_intel - tiempo_amd)
        
        print(f"{tamano:<15} {tiempo_intel:<20.4f} {tiempo_amd:<20.4f} {diferencia:<15.4f}")
    
    print("="*70)
    
# Configurar estilo de Seaborn
sns.set_theme(style="whitegrid")
sns.set_context("notebook", font_scale=1.2)
maquina_intel = 'Intel Core i5 - Windows'
maquina_AMD = 'AMD Ryzen 7 - Linux'
# Leer datos del CSV
df_intel = pd.read_csv(f'data/resultados_rendimiento_intel.csv')
df_AMD = pd.read_csv(f'data/resultados_rendimiento_AMD.csv')
grafico_rendimiento_operaciones(df_intel,maquina_intel)
grafico_rendimiento_operaciones(df_AMD,maquina_AMD)
comparativa_maquinas_multiplicacion(df_intel,df_AMD)
