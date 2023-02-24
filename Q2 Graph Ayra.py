import plotly.express as px
import pandas as pd

df = pd.read_csv("C:\\Users\\ayraa\\Desktop\\output_file2.csv", header=None)

fig = px.scatter_3d(df, x=0, y=3, z=4,color=5)
fig.show()