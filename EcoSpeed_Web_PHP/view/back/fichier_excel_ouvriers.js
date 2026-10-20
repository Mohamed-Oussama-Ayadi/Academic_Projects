

        $(function () 
        {
            $('[id*=btnExport]').on('click', function () {
                ExportToExcel('table_des_ouvriers');
                location.reload();
            });
        });


        function ExportToExcel(Id) 
        {
            var tab_text = "<table border='2px'><tr>";
            var textRange;
            var j = 0;
            tab = document.getElementById(Id);
            var headerRow = $('[id*=table_des_ouvriers] tr:first');
            tab_text += headerRow.html() + '</tr><tr>';
            var rows = $('[id*=table_des_ouvriers] tr:not(:has(th))');
            for (j = 0; j < rows.length; j++) {
                if ($(rows[j]).css('display') != 'none') {
                    tab_text = tab_text + rows[j].innerHTML + "</tr>";
                }
            }
            tab_text = tab_text + "</table>";
            tab_text = tab_text.replace(/<A[^>]*>|<\/A>/g, ""); //remove if u want links in your table
            tab_text = tab_text.replace(/<img[^>]*>/gi, ""); // remove if u want images in your table
            tab_text = tab_text.replace(/<input[^>]*>|<\/input>/gi, ""); // reomves input params
            var ua = window.navigator.userAgent;
            var msie = ua.indexOf("MSIE ");
                            //other browser not tested on IE 11
                sa = window.open('data:application/vnd.ms-excel,' + encodeURIComponent(tab_text));
            
            return (sa);
        }
 

    
