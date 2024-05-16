<!DOCTYPE html>
<html>

<head>
    <title>Update Interval</title>
</head>

<body>
    <h1>Update Interval</h1>
    <form id="intervalForm">
        <label for="interval">Enter interval in seconds:</label>
        <input type="number" id="interval" name="interval" min="1" required>
        <button type="submit">Update Interval</button>
    </form>

    <script>
        document.getElementById('intervalForm').addEventListener('submit', function(event) {
            event.preventDefault();
            var interval = document.getElementById('interval').value;

            fetch('/update-interval', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json'
                    },
                    body: JSON.stringify({
                        interval: interval
                    })
                })
                .then(response => response.json())
                .then(data => {
                    if (data.success) {
                        alert('Interval updated successfully!');
                    } else {
                        alert('Failed to update interval.');
                    }
                });
        });
    </script>
</body>

</html>