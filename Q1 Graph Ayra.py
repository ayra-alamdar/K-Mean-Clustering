import plotly.express as px
import pandas as pd

df = pd.read_csv("C:\\Users\\ayraa\\Desktop\\output.csv", header=None)

fig = px.scatter(df, x=1, y=2, color=3)
fig.show()