import QtQuick
import QtCharts

ChartView {
    id: root

    property LineSeries mainSeries: lineSeries

    LineSeries {
        id: lineSeries
        name: "Audio Sample Rate"
        axisX: ValueAxis {
            id: xValues
            min: 0
            max: 2000.0
        }
        axisY: ValueAxis {
            id: yValues
            min: -1.0
            max: +1.0
        }
    }

    function updateChart(x, y) {
        print(x, y)
        lineSeries.append(x, y)
        lineSeries.append((x + 0.01), -y)
        if (x > xValues.max) {
            xValues.min += 0.1
            xValues.max += 0.1
            lineSeries.remove(0)
        }
    }
}
